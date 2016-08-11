#include <stdio.h>
#include <limits.h>
int main(void)
{
	int a[10] = {1,2,3,4,5,16,7,8,9,0};
	int *i = NULL;
	int max = INT_MIN;
	int position;

	for(i=a; i<&a[10]; i++)
	{
		printf("%4d", *i);
	}
/*
	for(i=0; i<10; i++)
	{
		printf("%4d", *(a+i));
	}
*/
	putchar('\n');
	for(i=a; i<&a[9]; i++)
	{
		if (*i > max) 
		{
			max = *i;
			position = i - &a[0] + 1;
		}
	}
	printf("%4d%4d", max, position);
	putchar('\n');

return 0;
}