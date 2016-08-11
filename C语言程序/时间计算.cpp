#include <stdio.h>
#include <time.h>
int main(void)
{
	double t1, t2, sum = 0.0;
	int i, j;

	for (j=0; j<5; j++)
	{
		t1 = (double)clock()/1000;

		for(i=0; i<1e8; i++);

		t2 = (double)clock()/1000;
		sum += t2-t1;
		printf("第%d次运行了 %.4lf\n",j+1,t2-t1);
	}

	printf("\n平均用时 %.4f\n\n",sum/5);

return 0;
}