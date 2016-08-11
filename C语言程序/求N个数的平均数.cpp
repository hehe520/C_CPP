#include <stdio.h>

float ave(int n)
{
	int num, i=1, sum=0;
	float a = 0.0f;

	while(n>=i)
	{
	printf("请输入第 %d 个数___",i);
	scanf("%d",&num);
	getchar();
	if (num>0)
	{
	sum += num;
	}
		else
		{ 
			printf("\n输入错误\n请重新输入\n");	
			continue;
		}
		i++;
	}
	a = (float)sum/n;

	return a;
}

int main(void)
{
	int k=1;

	printf("输入n个正整数，求平均值");
	be : printf("\n请输入要求几个数的和？__");
	scanf("%d",&k);
	if (k>0)
		printf("\n平均值是：%.3f\n\n", ave(k));
	else 
	{
	printf("\n输入错误！\n");
	goto be;
	}

return 0;
}