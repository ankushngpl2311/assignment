#!/bin/bash
first_ext=`echo "$1" | cut -d'.' -f2`
second_ext=`echo "$1" | cut -d'.' -f3`


if [ "$first_ext" = "zip" ] ; then
    unzip $1 
elif [ "$second_ext" = "gz" ] ; then
    tar -xvzf $1
elif [ "$first_ext" = "tar" ] ; then
    tar -xopf $1
elif ["$second_ext" = "bz2" ] ; then
    tar -xvjf $1
elif ["$first_ext" = "bz2" ]; then
    bzip2 -d $1
else
    echo"Not a compressed file"
fi
