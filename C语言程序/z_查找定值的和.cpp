#include <stdio.h>
int main(void)
{
	int i, k, a[8]={1,2,3,4,5,6,7,8}, temp, flag, num;
	int *p1, *p2;

	printf("在数组中查找和为给定值的两个数字\n\n");
	printf("请输入8个整数\n");
	for(k=0; k<=7; k++) scanf("%d",&a[k]);

	printf("\n请输入一个定值___");
	scanf("%d",&num);

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

	p1 = &a[0];
	p2 = &a[7];

	do {
		if (*p1 + *p2 < num) p1++;
		if (*p1 + *p2 > num) p2--;
	}
	while (*p1 + *p2 != num && *p1 < *p2);

	if (*p1 + *p2 == num)
		printf("\n%d + %d = %d\n\n",*p1, *p2, num);
	else printf("未找到这样的两个数\n");

return 0;
}
/*
先从小到大排序，数组始位放一个指针p1，末位放一个指针p2
两个指针，相向而行，直到发现有适合的数，
复杂度：不知道，
*/