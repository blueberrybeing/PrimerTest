#include <stdio.h>

char stack[512];
int top = 0;

void push(char c)
{
	stack[top] = c;
	top++;
}

char pop(void)
{
	top--;
	return stack[top];
}

int is_empty(void)
{
	return top == 0;
}

#define LEN 3
char buf[LEN] = {'a', 'b', 'c'};

void print_backward(int pos)
{
	if (pos == LEN)
		return;
	print_backward(pos + 1);
	putchar(buf[pos]);
}

int main(void)
{
	push('a');
	push('b');
	push('c');
	
	while(!is_empty())
		putchar(pop());
	putchar('\n');
	
	print_backward(0);
	putchar('\n');

	int i = 0xcffffff3;
	printf("%x\n", 0xcffffff3 >> 2);
	printf("%x\n", i >> 2);
	signed int j = 0x40000000;
	j = j << 1;
	printf("%x\n", j);
	printf("%d\n", j);
	printf("%d\n", 0x40000000 << 1);
	printf("%d\n", 0x80000000);


	/* mask */
	printf("-----------mask-------------\n");
	unsigned int a, b, mask = 0x0000ff00;
	a = 0x12345678;
	b = (a & mask) >> 8;
	printf("%x\n", b);
	return 0;
}

