#include <stdio.h>
int main(void)
{
	int an=0,sn=0,i=0;

	printf("求1+3+5+7+…+555 的和\n\n");
	while(an < 555)
	{
	an = 2*i+1;
	sn += an;
	i++;
	}
	printf("1+3+5+7+…+555 的和为 %d\n\n",sn);

	return 0;
}