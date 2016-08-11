#include <stdio.h>
int main(void)
{
	int x, y, z;

	printf("百元百鸡问题\n");
	for (x=0; x<=100; x++)
	{
		for (y=0; y<=100; y++)
		{
			z = 100 - x - y;
			if (x + y + z == 100 
				&& 5*x + 3*y + (1.0/3.0)*z == 100.0)
			{
			printf("公鸡有 %d 只，母鸡有 %d 只，小鸡有 %d 只",x,y,z);
			putchar('\n');
			}
		}
	}

return 0;
}