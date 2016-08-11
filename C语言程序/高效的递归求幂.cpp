#include <stdio.h>

// 求 x^n 一般方法是进行 n-1 次的自乘, 复杂度O(n)
// 这里用高效的递归算法, 可将复杂度降到 O(log n)
// 公式: x是偶数: x^n = x^(n/2) * x^(n/2)
// x 是奇数 x^n = x^((n-1)/2) * x^((n-1)/2) * x

int count;		// 记录乘法次数

// 这里只实验 double 型, 数据溢出可用其他数据类型
double pow(int x, int n)
{
	count++;			// 测试用, 实际可以删掉
	if (n == 0) return 1;		// x^0 == 1
	else if (n == 1) return x;	// x^1 == x
	else if (n % 2 == 0)		// 偶数
		return pow(x * x, n / 2);
	else return pow(x * x, n / 2) * x;
}

int main(void)
{
	int x, n;

	count = 0;
	printf("请输入底数和指数: ");
	scanf("%d %d", &x, &n);
	printf("结果: %0.lf\n", pow(x, n));
	printf("执行了 %d 次乘法\n", count);

	return 0;
}