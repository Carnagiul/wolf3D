#!/bin/bash
if [ $# -ge 1 ]
then
	PROCESSID=$(pgrep -f $1)
	#PROCESSID=$(ps | grep "wolf3d" | grep -v "grep" | sed 's/^[ ]*//g' | cut -d" " -f1)
	leaks -q $PROCESSID
else
	echo "Usage: ./leaks.sh <projectname>"
fi
