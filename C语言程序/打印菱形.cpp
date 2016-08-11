#include <stdio.h>
int main()
{
	int i, j, k;
	int n, times, times2;

	scanf("%d", &n);
	for (i=2*n-1; i>0; i--)
	{
		times = i > n ? (i-n) : (n-i);
		for (j=0; j<times; j++)  //´òÓ¡¿Õ¸ñ
		{
			printf(" ");
		}

		times2 = 2 * (n - times) -1;
		for (k=0; k<times2; k++)
		{
			printf("*");
		}
		printf("\n");
	}

return 0;
}