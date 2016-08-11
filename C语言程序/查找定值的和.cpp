#include <stdio.h>
int main(void)
{
	int a[30] = {0};
	int i, n, num;
	int left, right;

	scanf("%d",&n);
	left = 0;
	right = n-1;
	for (i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&num);

	while (left < right)
	{
	
		if (a[left] + a[right] > num)
		{
			right--;
		}
		if (a[left] + a[right] < num)
		{
			left++;
		}
		if (a[left] + a[right] == num)
		{
			printf("%d + %d = %d\n",a[left],a[right],num);
			left++;
			right--;
		}
	}

return 0;
}