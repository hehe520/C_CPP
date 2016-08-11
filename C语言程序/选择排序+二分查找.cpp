#include <stdio.h>

int a[10] = {10, 20, 15, 36, 99, 3, 56, 43, 33, 20};

int *show(int *a)
{
	int i;
	for (i=0; i<10; i++)
	{
		printf("%4d", a[i]);
	}
	printf("\n");

	return a;
}

int *sort(int *a) // 选择排序
{
	int i, j;
	int min;
	int pos;
	int t;

	for (i=0; i<10; i++)
	{
		min = a[i];
		for (j=i; j<10; j++)
		{
			//去后面找一个更小的
			if (a[j] < min)
			{
				min = a[j];
				pos = j;
			}
		}
		// 如果最小值不是自己才交换
		if (min != a[i])
		{
			t = a[pos];
			a[pos] = a[i];
			a[i] = t;
		}
	}
	
	return a;
}

int find(int *a, int num)  // 二分查找
{
	int left = 0;
	int right = 10-1;
	int mid;
	int flag = 0;

	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == num)
		{
			flag = 1;
			break;
		}
		if (a[mid] < num)
		{
			left = mid + 1;
		}
		if (a[mid] > num)
		{
			right = mid - 1;
		}
	}
	return flag;
}

int main(void)
{
	int i;
	int num;
	int times = 10;
	
	show(a);
	while (times--)
	{
		
		printf("enter a number: ");
		scanf("%d", &num);
		sort(a);
		if (find(a, num)) printf("find it!\n\n");
		else printf("no such a number!\n\n");
	}
	show(a);
	
	return 0;
}