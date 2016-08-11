#include <stdio.h>
#include <stdlib.h>

int cmp(const void *x, const void *y)
{
	int a, b;

	a = *((int *)x);
	b = *((int *)y);

	return a > b;
}

int main(void)
{
	int a[5] = {5, 4, 3, 2, 1};

	qsort(a, 5, sizeof(int), cmp);
	printf("%d %d %d %d %d\n\n", a[0],a[1],a[2],a[3],a[4]);

	return 0;
}
// c++ жа #include <algorithm>
// qsort(a, a+5, cmp);