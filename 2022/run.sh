#!/bin/sh

if [ $# -ne 1 ]; then
    echo "Usage $0 <day>"
    exit 1
fi

if [ $1 == "clean" ]; then
    rm *_part1
    rm *_part2
    echo "Cleaned successful"
    exit 0
fi

gcc $1/part1.c -o $1_part1
gcc $1/part2.c -o $1_part2
echo "$1_part1 and $1_part2 generated"
exit 0
