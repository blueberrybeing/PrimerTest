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
	if(x % 2 == 0)
		return 1;
	else
		retrun 0;
}

int main(void)
{
	print_logarithm(4);
	return 0;
}
