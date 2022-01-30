#!/bin/bash
# Read IP Addresses From Separated CSV File
# Writen by Kieran Bessert 1/28/2022
# Last Updated 1/29/2022
# ------------------------------------------

INPUT=mdl.csv
OLDIFS=$IFS
IFS=','

[ ! -f $INPUT ] && { echo "$INPUT file not found"; exit -1; }

echo "Script Running"

> mdl.list
> a.list
> b.list

grep -E -o "([0-9]{1,3}[\.]){3}[0-9]{1,3}" $INPUT >> a.list

while read ipAddr
do
	count=$(grep -o $ipAddr a.list | wc -l)
	if [ "$count" -gt 127 ]
   	then
   		count=127
   	fi
	if ( ! grep $ipAddr b.list )
	then
   		echo "$ipAddr,1,$count" >> b.list
 	fi
done < a.list
rm a.list
grep -v -E "(^127\.)([0-9]{1,3}[\.]){2}[0-9]{1,3}" b.list >> mdl.list
rm b.list
IFS=$OLDIFS
echo "Script Complete"
