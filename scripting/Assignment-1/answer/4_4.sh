#!/bin/bash

f=$1
all=$f/*

for i in $all
do
	ext=`echo "$i" | cut -d'.' -f2`
	mkdir $f/$ext 2>/dev/null
	mv $i $f/$ext	2>/dev/null	
done
