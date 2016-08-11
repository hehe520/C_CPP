#include <stdio.h>

int main()
{
	int i, j, k;
	int n;

	scanf("%d",&n);
	for (i=n; i>0; i--)
	{
		for (j=0; j<-(i-n); j++)
		{
			putchar(' ');
		}
		for (k=2*i-1; k>0; k--)
		{
			printf("#");
		}
		putchar('\n');
	}

	
return 0;
}