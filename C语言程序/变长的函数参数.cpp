#include <stdio.h>
#include <stdarg.h>

int add(int num,...)	// num 记录个数, 也表示从 num 后开始入栈
{
	int sum = 0;
	int an;
	int i;
	va_list aq;
	
	va_start(aq, num);
	for (i=0; i<num; i++)
	{
		an = va_arg(aq, int);	// 取 int 型数据,char 取 字符型...
		sum += an;
	}
	va_end(aq);

	return sum;
}

int main(void)
{
	int sum;

	sum = add(1, 10);
	printf("sum = %d\n", sum);

	sum = add(2, 2, 3);
	printf("sum = %d\n", sum);

	sum = add(5, 2, 3, 4, 5, 6);
	printf("sum = %d\n", sum);

	return 0;
}