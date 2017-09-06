#include <stdio.h>

/* 
 * comment1
 * main: generate some simple output
 */

int foo(void)
{
	int i ;
	printf("%d\n",i);
	i = 777;
}

int main(void)
{
	for (int i = 0; i < 10; ++i)
	{
		printf("%c\n",'%');
	}
	printf(/* comment2 */"Hello, world.\n"); /* comment3 */

	foo();
	printf("--------------------------\n");
	foo();
	return 0;
}
