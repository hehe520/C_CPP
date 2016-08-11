#include <stdio.h>
#include <math.h>

int main(void)
{
	int i,ge,shi,bai,qian;

	printf("搜索一万以内的水仙花数\n");

	for(i=100; i<=999; i++)
	{
	bai = i/100;
	shi = (i%100)/10;
	ge = i%10;

	if (ge+10*shi+100*bai ==
		pow(ge,3)+pow(shi,3)+pow(bai,3))
		printf("%d\n",i);
	}

	for(i=1000; i<=9999; i++)
	{
	qian = i/1000;
	bai = (i%1000)/100;
	shi = (i%1000)%100/10;
	ge = i%10;
	
	if (ge+10*shi+100*bai+1000*qian ==
		pow(ge,4)+pow(shi,4)+pow(bai,4)+pow(qian,4))
	printf("%d\n",i);
	}
return 0;
}