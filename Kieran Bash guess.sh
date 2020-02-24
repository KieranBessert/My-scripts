#!/bin/bash

#created by Kieran

DOM=`date -d "$D" '+%d'`

echo "Welcome to the Guessing Game!!"
echo "What is my favorite color?"

#User input
read GUESS

#logic
if [ $GUESS = "Blurple" ]; then
	echo "You are correct!"
	echo "What day of the month is it?"
	read GUESS
	if [ $GUESS = $DOM ]; then
		echo "Exactly!"
	else
		echo "You are WRONG!"
		exit
	fi


elif [ $GUESS = "blurple" ]; then
	echo "Use capital letters, Jerk!"
	/home/kabessert1994/Scripts/guess.sh
	exit
else
	echo "Nope! Too Bad!"
	exit
fi

echo "You Win!"
