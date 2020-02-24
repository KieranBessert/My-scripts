#!/bin/bash
#created by Kieran Bessert

#first for loop

#for VAR in `seq 1 3`; do
#	echo $VAR "Hello There."
#done

#first while loop

#COUNTER=0
#while [ $COUNTER -lt 5 ]; do
#	let COUNTER=COUNTER+1
#        echo $COUNTER
#done

#While loop text redirect

while read VAR; do
	echo "Bonk"
done < names.txt
