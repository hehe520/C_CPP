#include <stdio.h>
int main(void)
{
	char a[3][4] = {0};
	int i, j;
	char (*p)[4];

	p = a;
	printf("数组首地址: %x\n\n", a);
	for (i=0; i<3; i++)
	{
		printf("第 %d 行 a[%d][j]\n",i,i);
		for (j=0; j<4; j++)
		{
			printf("%x\n", &a[i][j]);
		}
		printf("\n");
	}
	for (i=0; i<3; i++)
	{
		printf("p+%d 地址 %x\n",i,p++);
	}
	printf("\n");

	p=a;
	printf("%x \t %x\n",*(*(p+1)+1),a[0]);

return 0;
}