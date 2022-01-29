#!/bin/bash
# Read IP Addresses From Separated CSV File
# Writen by Kieran Bessert 1/28/2022
# Last Updated 1/28/2022
# ------------------------------------------

INPUT=mdl.csv
OLDIFS=$IFS
IFS=','
# Check for file input
[ ! -f $INPUT ] && { echo "$INPUT file not found"; exit -1; }

if [ -f mdl.list ]
then
	echo "File Exists"
	ls
else
	> mdl.list
fi

while read lastUpdate domain ipAddr domain2 exploit a b c d
do
	if ! grep "$ipAddr" mdl.list 
	then
   		count=$(grep -o "$ipAddr" mdl.csv | wc -l)
   		echo "$ipAddr $count" >> mdl.list
 	fi
done < $INPUT
IFS=$OLDIFS
echo "Script Complete"
