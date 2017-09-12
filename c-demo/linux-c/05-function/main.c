#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

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

int test_for_loop(int n)
{
	int result = 1;
	for(int i = 1; i <= n; ++i)
		result *= i;
	return result;
}

int is_leap_year(int year)
{
	if(year % 4 == 0 && year % 100 != 0)
		return 1;
	if(year % 400 == 0)
		return 1;
	return 0;
}

int is_prime(int n)
{
	/*
	for (int i = 2; i <= n; ++i)
	{
		if (n % i == 0)
			break;
	}
	if (i == n)
		return 1;
	else
		return 0;
	*/
	if (n < 2)
		return 0;
	for (int i = 2; i < n/2 + 1; ++i)
		if (0 == n % i)
			return 0;
	return 1;
}

void print_nine_nine()
{
	int i, j;
	for (i = 1; i <= 9; ++i)
	{
		for (j = 1; j <= 9; ++j)
	{
			if (j <= i)
				printf("%d\t", i * j);
		}
		printf("\n");
	}
}

/*
void test_gestures()
{
	char gestures[3][10] = { "fuck", "stone", "cloth"};
	int man, computer, result, ret;

	srand(time(NULL));
	while(1)
	{
		computer = rand() % 3;
		printf("\nInput your gesture");
	}
}
*/

int main(void)
{
//	print_logarithm(4.0);
//	printf("-------%d--------\n", test_for_loop(3));
	print_nine_nine();

	char gesture[3][10] = {"fuck", "stone", "cloth"};
	printf("---Your gesture:%s-----\n", gesture[1]);
	return 0;
}
