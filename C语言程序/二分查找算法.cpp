#include <stdio.h>
int main(void)
{
	int a[40] = {0};
	int i, n, num;
	int left = 0;
	int right;
	int mid;

	scanf("%d",&n);
	right = n-1;
	//数组是从0到n-1的,
	for (i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&num);

	while(left <= right)
	{
		mid = (left + right) / 2;
//		printf("%d = (%d + %d) /2  %d==%d\n",mid, left, right,num,a[mid]);
		if (num > a[mid])
		{
			left = mid + 1;
		}
		if (num < a[mid])
		{
			right = mid - 1;
		}
		if (num == a[mid])
		{
			printf("found it %d\n",a[mid]);
			break;
		}
	}
	if (num != a[mid])
	{
		printf("not found\n");
	}

	scanf("%d",&num);	
return 0;
}