#!/usr/bin/env bash
# -*- coding: utf-8 -*-

function _usage() {
    echo "usage: COMMAND [-inHhpR] -p<pattern1> -p<pattern2> ... <filename>"
    echo "-i : ignore case"
    echo "-n : show line number"
    echo "-H : show filename"
    echo "-h : show header"
    echo "-p : specify pattern"
    echo "-R : search recursively"
}

declare -a patterns

while getopts "iHhnRp:" opt; do
    case $opt in
	i)
	    ignorecase_flag=true ;;
	H)
	    filename="FILENAME," ;;
	n)
	    linum="NR," ;;
	p)
	    patterns+=( "$OPTARG" ) ;;
	h)
	    header_flag=true ;;
	R)
	    recursive_flag=true ;;
	\?)
	    _usage
	    exit 1 ;;
    esac
done

if [[ -n $filename || -n $linum ]]; then
    colon="\":\","
fi

shift $(( $OPTIND - 1 ))

if [[ $ignorecase_flag == true ]]; then
    for s in "${patterns[@]}"; do
        result+=" && s~/${s,,}/"
    done
    result=${result# && }
    result="{s=tolower(\$0)} $result"
else
    for s in "${patterns[@]}"; do
        result="$result && /$s/"
    done
    result=${result# && }
fi

result+=" { print "$filename$linum$colon"\$0 }"

if [[ ! -t 0 ]]; then 		# pipe case
    cat - | awk "${result}"
else
    for f in "$@"; do
	if [[ -d $f ]]; then # directory
	    if [[ $recursive_flag == true ]]; then
		find -L $f -not -path '*/\.*' -type f -print0 2>/dev/null | while IFS= read -r -d '' ff; do
		    if file "$ff" | grep -q "text"; then # only search text file
			[[ $header_flag == true ]] && echo "########## processing $ff ##########"
			awk "${result}" "$ff"
		    fi
		done
	    fi
	else				  # file
	    if file "$f" | grep -q "text"; then # only search text file
		[[ $header_flag == true ]] && echo "########## processing $f ##########"
		awk "${result}" "$f"
	    fi
	fi

    done
fi
