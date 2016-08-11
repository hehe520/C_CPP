#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int ran, num, count = 0;

	printf("猜数游戏\n请输入1～100之间整数__");
	srand(time(NULL));
	ran = rand()%100+1;

	while(1)
	{
		while(1)
		{
			count++;

			scanf("%d",&num);
			fflush(stdin);
			if ((num>=1) && (num<=100)) break;
			else printf("\n您输入错误，请重新输入__");
		}
		if (count >= 11) 
		{
			printf("\n您猜了10次仍未猜中，结束游戏\n");
			break;
		}
		printf("\n总共猜了 %d 次",count);
		if (num < ran) printf("\nWrong!，您猜小了__");
		if (num > ran) printf("\nWrong!，您猜大了__");
		if (num == ran)
		{
			printf("\nRight!，您猜对了!\n");
			break;
		}
	}
	getchar();

return 0;
}
