#!/bin/bash
first_num=0
second_num=0
echo -n "Enter the first number -->"
read first_num
echo -n "Enter the second number -->"
read second_num

echo "first number + second number = $((first_num + second_num))"
echo "first number - second number = $((first_num - second_num))"
echo "first number * second number = $((first_num * second_num))"
echo "first number / second number = $((first_num / second_num))"
echo "first number % second number = $((first_num % second_num))"

echo "first number raised to the"
echo "power of the second number   = $((first_num ** second_num))"


number=0

echo -n "Enter a number > "
read number

echo "Number is $number"
if [ $((number % 2 )) -eq 0 ] ;then
	echo "Number is even"
else
	echo "Number is odd"
fi

set -x
seconds=0
echo -n "Enter number of seconds >"
read seconds

hours=$((seconds / 3600))
seconds=$((seconds % 3600))
minutes=$((seconds / 60))
seconds=$((seconds % 60))
echo "$hours hour(s) $minutes minute(s) $seconds second(s)"
