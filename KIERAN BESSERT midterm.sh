#!/bin/bash
#created by Kiean Bessert

#using a case statement to set up script like a command with options

case $1 in
	-c|--create)
		#get user input for name and favorite color
		echo "Please enter your: FIRSTNAME LASTNAME"
		read NAME
		echo "Please enter your favorite color"
		read COLOR

		#Checks if COLOR DIR exsists and tells user if it does
		#if not create COLOR DIR, places csv file in that dir
		[ -d "/tmp/$COLOR" ] && echo 'A directory for that color exists at /tmp/.' && echo "Bad luck $NAME!" || mkdir /tmp/$COLOR && awk '{print $3", "$4", "$5", "$2"-000"}' $2 > /tmp/$COLOR/midterm.csv && echo "Done."
		;;
	-*|--*)
		#Directing to use the correct flag
		echo "Use the -c flag."
		;;
	*)
		#catchall for no/incorrect flags
		echo "Use following syntax: 'midterm.sh -c /path/to/FILENAME'"
		;;
esac
#in testing directories are made and csv files are palced in those files.
#cannot get it to cd into new dir /tmp/$COLOR no matter my order
#if no file is pointed to in $2 the dir will be made as will the csv, however the csv will be blank and the user will have to ctrl-c to quit the program
