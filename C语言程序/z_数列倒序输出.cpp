#include <stdio.h>
int main(void)
{
	int a[5] = {1,2,3,4,5};
	int *i = NULL;
	int *j = NULL;
	int t;

	for(i=a; i<&a[5]; i++)
	{
		printf("%4d", *i);
	}
	putchar('\n');
	for(i=a, j=&a[4]; i<j; i++,j--)
	{
		t = *i;
		*i = *j;
		*j = t;
	}
	for(i=a; i<&a[5]; i++)
	{
		printf("%4d", *i);
	}
	putchar('\n');

return 0;
}