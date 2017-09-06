#include <stdio.h>
#include <math.h>

/* 
 * comment1
 * function test 
 */

void print_logarithm(double x)
{
	if (x <= 0.0) 
	{
		printf("Positive numbers only,please.\n");
		return;
	}
	printf("The log of %f is %f\n", x, log(x));
}	

int is_even(int x)
{
	/*
	if(x % 2 == 0)
		return 1;
	else
		retrun 0;
	*/
	return !(x % 2);
}

int is_leap_year(int year)
{
	if(year % 4 == 0 && year % 100 != 0)
		return 1;
	if(year % 400 == 0)
		return 1;
	return 0;
}

int main(void)
{
	print_logarithm(4);
	return 0;
}
