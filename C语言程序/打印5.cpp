#include <stdio.h>

int n;

void print(int n, char style, char flag)
{
	int i, j;
	for (i=0; i<n; i++)
	{
		if (style == 'c') 
		{
		printf("\n");
		if (flag == 'r') 
		{
			for (j=0; j<n+1; j++)
			  printf(" ");		  
		}
		printf("*");
		}
		if (style == 'r') printf("*");
	}
}

int main(void)
{
	printf("请输入大小:");
	scanf("%d",&n);

	print(n, 'r','l');
	print(n-2, 'c','l');
	putchar('\n');
	print(n, 'r','l');
	print(n-2, 'c','r');
	putchar('\n');
	print(n, 'r','l');
	putchar('\n');

	return 0;
}

/*
print(int n, char style, char flag)

n 表示书写的长度，
style 表示 r(raw)横着写， c(colnmn)竖着写，
flag 表示写在左边l(left) 还是右边r(right)
*/