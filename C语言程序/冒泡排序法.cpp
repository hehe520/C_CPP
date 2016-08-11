#include <stdio.h>

int main(void)
{
    int test[10],i,k,j,temp,flag;

	printf("冒泡排序法，从小到大\n");
	printf("请输入十个整数\n");

	for(i=0; i<10; i++)
	{
	printf("第 %d 个  ",i+1);
	scanf("%d",&test[i]);
	getchar();     //吸收多余回车键
	}

	for(k=0; k<=9; k++)
	{
	flag = 1;
	for(i=0; i<9; i++)
	{
		if (test[i] > test[i+1])
		{
		temp = test[i];
		test[i] = test[i+1];
		test[i+1] = temp;
		flag = 0;         //查看是否发生了交换
		}
	}
	printf("第 %d 次排序的结果",k+1);
	for(j=0; j<10; j++) printf("%5d",test[j]);
	putchar('\n');
	if (flag==1) break;
	}

return 0;
}