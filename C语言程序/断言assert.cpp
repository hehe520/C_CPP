#include <stdio.h>
#include <assert.h>

int main(void)
{
	int i;
	
	scanf("%d", &i);
	assert(i > 10);			// 断言, 假定 i 要大于 10, 才往下走
	printf("hello\n");

	return 0;
}