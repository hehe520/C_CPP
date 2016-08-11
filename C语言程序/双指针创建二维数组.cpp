#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int num = 1;
	int **p = 0;
	int i, j;

	p = (int **)malloc(5 * sizeof(int *)); //5个存放指针的位置

	for (i=0; i<5; i++)
	{
		*(p+i) = (int *)malloc(4 * sizeof(int));
	}

	for (i=0; i<5; i++)
	{
		for (j=0; j<4; j++)
		{
			p[i][j] = num++;
		}
	}

	printf("%d\n", p[0][2]);
	
	for (i=0; i<5; i++)
	{
		free(*(p+i));
	}
	free(p);

	return 0;
}