#!/bin/bash
#created by Kieran Bessert
NUM=7
#intro
echo "Welcome to the Number Guessing Game!"
echo "You have 3 tried to guess the number between 1 and 10!"
echo "What is your first guess?"

#User input
read GUESS
#Logic
if [ $GUESS -eq $NUM ]; then
	echo "YOU WIN!!"
	exit
fi
if [ $GUESS -lt $NUM ]; then
	echo "Higher!"
else
	echo "Lower!"
fi

#guess 2
read GUESS2
if [ $GUESS2 -eq $NUM ]; then
	echo "YOU WIN!!"
	exit
fi
if [ $GUESS2 -lt $NUM ]; then
	echo "Higher!"
else
	echo "Lower!"
fi

#guess 3
read GUESS3
if [ $GUESS3 -eq $NUM ]; then
	echo "YOU WIN, FINALLY!!!"
	exit
fi
if [ $GUESS3 -lt $NUM]; then
	echo "HIGHER!!!"
else
	echo "LOWER!!!"
fi

#signoff
echo "That's too bad, try again?"
exit
