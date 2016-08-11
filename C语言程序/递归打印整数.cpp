// 递归打印整数

#include <stdio.h>

// 基本项:
// n 只有一位，就直接输出
// n 有多位，输出第一位
void show(int n)
{
	if (n >= 10) 
	{
		show(n / 10);
	}
	// 回溯的时候，也要把当前位数输出
	printf("%d", n % 10);
}

int main(void)
{
	show(123);
	printf("\n");

	return 0;
}