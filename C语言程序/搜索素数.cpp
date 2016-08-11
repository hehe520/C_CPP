#include <stdio.h>
#include <math.h>

int main(void)
{
	int i,k,j=1;

	printf("搜索100以内的素数\n");
	for(i=2;i<=100;i++)
	{
		for(k=2; k<sqrt(i); k++)
		{
			if (i%k == 0) {j=0; break;}
		}
		if (j) printf("%d\n",i);
		j=1;     //及时关闭开关
	}
	return 0;
}