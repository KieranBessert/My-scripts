#!/bin/bash
#created by Kieran

#case matches

echo "what is your favorite linux distro?"
read VAR

case $VAR in
	Debian)
		echo "That's a good one!"
		;;
	Ubuntu)
		echo "That's my favorite!"
		;;
	Redhat|Fedora|CentOS)
		echo "OK, nerd"
		;;
	Windows|Mac)
		echo "No"
		;;
	*)
		echo "Try again"
		;;
esac
