#include <stdio.h>
#include <string.h>

int main(void)
{
	int i, n, k, j;
	int a[100];

	scanf("%d%d",&n, &k);
	memset(a, -1, sizeof(a));
	for (i=1; i<=k; i++) // 第i个人
	{
		for (j=1; j<=n; j++)  //第i盏灯
		{
			if (j%i == 0)
			{
				a[j] = -a[j];
			}
		}
	}

	for (j=1; j<=n; j++)
	{
		if (a[j] == 1)
		{
			printf("%4d",j);
		}
	}
return 0;
}