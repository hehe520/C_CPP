#include <stdio.h>

int count = 0;

void move(int i, char c1, char c2)
{
	count++;
	printf("%c  ->  %c\n", c1, c2);
}

void find(int n, char x, char y, char z)
{
	if (n == 1) move(n, x, z);
	else
	{
		find(n-1, x, z, y);
		move(n, x, z);
		find(n-1, y, x, z);
	}
}

int main(void)
{
	int n;
	
	scanf("%d", &n);
	find(n, '1', '2', '3');
	printf("count = %d\n", count);
	
	return 0;
}
