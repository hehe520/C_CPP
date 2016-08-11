#include <stdio.h>
int main(void)
{
	int tri[25][25] = {0};
	int i, j, n;

	printf("请输入杨辉三角形的大小");
	scanf("%d",&n);
	i = j = 0;
	for (i=0; i<n; i++)
	{
		j=0; 
		tri[i][j] = 1;   //第一个总为1
		printf("%5d", tri[i][j]);

		for (j=1; j<=i; j++)   //从第2行开始
		{
			tri[i][j] = tri[i-1][j] + tri[i-1][j-1];
			printf("%5d", tri[i][j]); 
		}
		putchar('\n');
	}

return 0;
}