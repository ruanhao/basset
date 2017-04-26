#!/usr/bin/env bash
# -*- coding: utf-8 -*-

# Usage: $0 file1 file2 ...

# When this exits, exit all back ground process also.
trap 'kill $(jobs -p)' EXIT

# iterate through the each given file names,
for file in "$@"; do
    # show tails of each in background.
    tail -F $file | awk '
  { flag = 0 }
  /INFO/    { print "\033[32m" $1 "\033[39m"; flag = 1 }
  /ERROR/   { print "\033[31m" $0 "\033[39m"; flag = 1 }
  flag == 0 { print $0; }
' &
done

# wait .. until CTRL+C
wait