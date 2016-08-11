// 有数组 a1, a2, ... an
// 假设 [1..n] 已经排好序
// 把 n+1 放到 [1..n]中的恰当位置

#include <stdio.h>

void show(int a[])
{
	int i;

	for (i=0; i<10; i++) 
		printf("%d, ", a[i]);
	printf("\n");
}

int main(void)
{
	int a[10] = {1,6,4,3,5,9,8,7,2,0};
	int i; 
	int j;
	int data;

	show(a);
	for (i=1; i<10; i++)
	{
		data = a[i];	// 待插入的元素
		j = i-1;
		// [] [] [j] [data]
		while (j>=0 && data < a[j])	 // 升序
		{
			a[j+1] = a[j];
			j--;
		}
// 退出while时，j==-1 或 data不小于a[j], 所以插到a[j+1]处
		a[j+1] = data;
	}
	show(a);

	return 0;
}