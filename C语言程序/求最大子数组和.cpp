#include <stdio.h>
int main(void)
{
	int temp=0, b[9], i, max;
	int a[8];

	printf("找出子数组和的最大值\n请输入8个整数\n");
	for(i=0;i<=7;i++) scanf("%d",&a[i]);

	printf("原数组\t");
	for(i=0;i<=7;i++) printf("%4d",a[i]);
	putchar('\n');

	b[0]=a[0];        //计算所有和
	for(i=1;i<=8;i++)
		b[i] = b[i-1] + a[i];
	

	for(i=1;i<=8;i++)    //找出最大的
		if (b[i-1]<b[i]) max=b[i];

	printf("最大的子数组和是 %d\n",max);

return 0;
}
/*
思路，计算所有子数组和，保存到b[9]，然后找出最大的，
不知道复杂度是不是O(n^2)
*/