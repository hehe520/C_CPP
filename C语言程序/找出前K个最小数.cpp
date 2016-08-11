#include <stdio.h>
int main(void)
{
	int i, k, a[8], flag, temp;

	printf("输出前3个最小的数\n请输入8个整数\n");
	for(i=0;i<=7;i++) scanf("%d",&a[i]);

	printf("原数组\t");
	for(i=0;i<=7;i++) printf("%4d",a[i]);
	putchar('\n');

	for(k=0; k<=7; k++)
	{
	flag = 1;
	for(i=0; i<7; i++)
	{
		if (a[i] > a[i+1])
		{
		temp = a[i];
		a[i] = a[i+1];
		a[i+1] = temp;
		flag = 0;         
		}
	}
	if (flag==1) break;
	}
	printf("最小的前3个数是\t");
	for(i=0;i<=2;i++) printf("%4d",a[i]);
	putchar('\n');

return 0;
}
/*
上课讲的算法忘记了，
我是先冒泡排序，然后选出前3个最小的，
复杂度不知道是不是O(nlog n)
*/