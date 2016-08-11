#include <stdio.h>

int max(int a, int b)
{
	//  如果 b 大, 那么find里面做的操作
	if (a < b) return 1;
	else return 0;
}

//  指向函数的指针   char (*p)(形参表)
int find(int a[], int (*p)(int a, int b) ) 
{
	int j = *(a);
	int i;
	for(i=0; i<4; i++)
	{
		//  使用改指针  (*p)(实参值)
		//  相当于      max(实参值)
		if ((*p)( *(a+i), *(a+i+1) ))
		{
			// 那么，把 *(a+i+1) 给 j
			j = *(a+i+1);
		}
	}
	return j;
}

int main(void)
{
	int (*f)(int a[], int (*p)(int a, int b)); 
	// 指向函数的指针
	int a[5] = {1,2,3,4,5};

	f = find;
	printf("max = %d\n", (*f)(a, max));
//上面语句等价于 	printf("max = %d\n", find(a, max));

	return 0;
}
