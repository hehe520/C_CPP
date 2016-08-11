#include <stdio.h>
#define MAX 5000

int main(void)
{
	int a[MAX];
	int i, j;

	for (i=1; i<MAX; i++) a[i] = 1;

	a[0] = a[1] = 0;
	for (i=1; i<MAX; i++)
	{
		if (a[i] == 1) 
		{
			for (j=i+i; j<MAX; j+=i)
			{
				a[j] = 0;
			}
		}
	}
	for (i=1; i<100; i++)
	{
		if (a[i] == 1) printf("%d\n",i);
	}

return 0;
}