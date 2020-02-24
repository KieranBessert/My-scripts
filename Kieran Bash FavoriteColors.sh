#!/bin/bash
sed s/Unknown/Brown/ NamesAndColors.txt |awk '{print "Hello my name is " $2,$1 " and my favorite color is " $3}' NamesAndColors.txt
