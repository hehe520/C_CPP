#include <stdio.h>
int main(void)
{
	int a[10], i, k, j, k1=0, j1=9, temp;
	int *p1, *p2;

	printf("奇数放前，偶数放后\n输入10个整数");

	for (i=0;i<=9;i++) scanf("%d",&a[i]);

	printf("未放前\t");
	for(i=0;i<=9;i++) printf("%3d",a[i]);
	putchar('\n');

	do {
		for(k=k1;k<=4;k++)      //p1指针从前向后
		{
		p1 = &a[k];
		if (*p1%2==0) {k1=k;break;}
		};

		for(j=j1;j>=5;j--)      //p2指针从后向前
		{
		p2 = &a[j];       
		if (*p2%2==1) {j1=j;break;}
		};
		if (j1==j && k1==k)     //发现两个奇偶不同
		{
		temp = a[k];
		a[k] = a[j];
		a[j] = temp;
		}
	} while(k!=5 && j!=4);      //直到两个指针都到了中间

	printf("\n放后\t");
	for(i=0;i<=9;i++) printf("%4d",a[i]);

	putchar('\n');

return 0;
}
/*
一个指针p1在前，一个p2在后，
向中间靠近，发现奇偶不同就对调，
复杂度 O(n)
*/