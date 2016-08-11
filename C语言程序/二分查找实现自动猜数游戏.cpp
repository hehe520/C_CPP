#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int ran, mid; 
	int count = 0;
	int left, right;

	printf("猜数游戏\n请输入1～100之间整数\n");
	srand(time(NULL));
	ran = rand()%100+1;
	left = 0;
	right = 100;
	//数的范围是[0, 100]

	while(1)
	{
		mid = (left + right) / 2;
		count++;
		if (mid < ran)
		{
			printf("\n我猜  %d\nWrong!，您猜小了\n",mid);
			left = mid + 1;
		}
		if (mid > ran)
		{
			printf("\n我猜  %d\nWrong!，您猜大了\n",mid);
			right = mid - 1;
		}
		if (mid == ran)
		{
			printf("\n我猜  %d\nRight!，恭喜，您猜对了!\n\n", mid);
			break;
		}
		//sleep(1000);
	}
	printf("总共猜了 %d 次\n\n",count);
	getchar();

return 0;
}
