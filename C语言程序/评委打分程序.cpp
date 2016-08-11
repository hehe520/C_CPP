#include <stdio.h>
int main(void)
{
	int i=1,j=1, num, g[100], max,min,sum;
	float ave=0.0f;

	sum = min = max = g[0] = 0;
    do {
	if(i>=2) printf("输入错误！\n"); 
	printf("输入评委数 ");
	scanf("%d",&num);
	getchar();
	fflush(stdin);
    putchar('\n');
	i++;
	}  
	while(num<=3 || num>30000);
	
	while(j<=num)
	{
	printf("第 %d 个评委请打分\n",j);
	scanf("%d",&g[j]);
	fflush(stdin);
	if (g[j] > g[j-1]) max = g[j];
    if (g[j] < g[j-1]) min = g[j];
	sum = sum + g[j];
	j++;
	}
	sum = sum -min -max;
	ave = (float)sum/(j-2);
	printf("\n去掉一个最高分 %d , 去掉一个最低分 %d",max,min);
	printf("\n 最终成绩 %.3f\n\n",ave);

return 0;
}