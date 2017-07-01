#!/usr/bin/env bash
# -*- coding: utf-8 -*-

function _usage() {
    echo "usage: COMMAND [-inHhp] -p<pattern1> -p<pattern2> ... <filename>"
    echo "-i : ignore case"
    echo "-n : show line number"
    echo "-H : show filename"
    echo "-h : show header"
    echo "-p : specify pattern"
}

declare -a patterns

while getopts "iHhnp:" opt; do
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
	[[ $header_flag == true ]] && echo "########## $f ##########"
	awk "${result}" $f
    done
fi
