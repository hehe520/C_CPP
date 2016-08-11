#include <string.h>
#include <stdio.h>
int main(void)
{
	int a[100] = {0};
	int n, i, j;
	int max = -1;
	int flag = 1;

	while (scanf("%d",&n) != EOF)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", a+i);
			if (a[i] >= max)
			{
				max = a[i];
			}
		}
		for (i=max; ; i++)
		{
			flag = 1;
			for (j=0; j<n; j++)
			{
				if (i%a[j] != 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag) 
			{
				printf("%d\n",i);
				break;
			}
		}
		flag = 1;
		max = -1;
		memset(a, 0, 100*sizeof(int));
	}

return 0;
}