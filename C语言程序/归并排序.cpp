#include <stdio.h>
#include <stdlib.h>

int a[8] = {8,7,6,5,4,3,2,1};

void combine(int a[], int left, int rightend, int leftend)
{
	int *t;
	int j = 0;
	int i, h;
	int right = leftend + 1;
	int k1 = left;
	int k2 = rightend; //记录a[]被修改的区间
	
	t = (int *)malloc((rightend-left+2)*sizeof(int));
	while (left <= leftend && right <= rightend)
	{
		if (a[left] <= a[right])
		{
			t[j++] = a[left++];
		}
		else 
		{
			t[j++] = a[right++];
		}
	}
	while (right <= rightend) t[j++] = a[right++];
	while (left <= leftend) t[j++] = a[left++];
	for (i=k1, h=0; i<=k2; i++, h++) 
	{
		a[i] = t[h];
	}
	// 还原排好序的区间，a[]从k1到k2，t[]从0到h
	free(t);
}

void cut(int a[], int left, int right)
{
	int mid;
	if (left < right) //不断分割
	{
		mid = (left + right) / 2;
		cut(a, left, mid);
		cut(a, mid+1, right);
		combine(a, left, right, mid);
		// 左区间，右区间，切开，合并
	}
}

int main(void)
{
	int i;
	
	for (i=0; i<8; i++) {printf("%4d", a[i]);}
	printf("\n\n排序后\n");
	cut(a, 0, 7);
	for (i=0; i<8; i++) {printf("%4d", a[i]);}
	printf("\n\n");
	
	return 0;
}