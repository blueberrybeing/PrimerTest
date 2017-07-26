#!/bin/bash

#The while command causes a block of code to be executed over and over, as long as the exit status of a specified command is true.

number=0
while [ "$number" -lt 10 ]; do
	echo "Number = $number"
	number=$((number + 1))
done

echo "-------------------------------------------------"

#The until command works exactly the same way, except the block of code is repeated as long as the specified command's exit status is false. 

number=0
until [ "$number" -ge 10 ]; do
	echo "Number = $number"
	number=$((number + 1))
done

#Building A Menu

press_enter()
{
	echo -en "\npress Enter to contiue"
	read
	clear
}

selection=
until [ $"selection" = "0" ]; do
	echo "
	PROGRAM MENU
	1 - Display free disk space
	2 - Display free memory
	0 - exit program
	"
	echo -n "Enter selection:"
	read selection
	echo ""
	case $selection in
		1 ) df ; press_enter ;;
		2 ) free ; press_enter ;;
		0 ) exit ; press_enter ;;
		* ) echo "please enter 1, 2 or 0" ; press_enter
	esac
done
