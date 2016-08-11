#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int num;

int ran(void)    //产生[5,35]随机数
{
	int r;
	r = rand()%31+5;
	return r;
}

void cls(void)   //清屏
{
	system("cls");
}

void win(void)
{
	printf("\n石子被取完了，玩家获胜！\n\n");
	num=0;
}

void lose(void)
{
	printf("\n石子被取完了，电脑获胜！\n\n");
	num=0;
}

int main(void)
{
	int b1=0, b2=1, player_num, comp_num;

	srand((unsigned)time(NULL));
	system("color 0a");
	num = ran();
	printf("\n石子游戏\n\n现在有 %d 个石子",num);
	printf("\n每次只能取 1 或 2 个哦！");

	while(num!=0) 
	{
	do
	{
		if (b2) {printf("\n\n请玩家开始取石子___");}
		if (b1) {cls(); printf("\n输入错误,每次只能取 1 或 2 个哦\n请重新输入___");}
		scanf("%d",&player_num);
		getchar();          //吸收回车键
		b1 = 1; 
		b2 = 0;
	}
	while ((player_num != 1) && (player_num != 2));
    
	b1 = 0;   //关闭开关
	b2 = 1;
	if (player_num < num)
	{
	num = num - player_num;
	printf("\n玩家取了 %d 个，还剩 %d 个\n",player_num, num);
	}
		else if (player_num = num)
		{
		win();
		}
			else
			{
			begin :printf("\n没有那么多石子了哦，请重新输入___");
			scanf("%d",&player_num);
			if (player_num != 1) goto begin;
			win();
			};

	computer :comp_num = rand()%2+1;

	if (num == 2 || num == 1) 
	{
		printf("\n电脑开始取石子...\n电脑取了 %d 个", comp_num);
		num = 0;
		lose();
	}
	if (comp_num < num) {
	printf("\n电脑开始取石子...\n电脑取了 %d 个", comp_num);
	num = num - comp_num;
	printf(",现在还剩 %d 个",num);
						}
		else if (comp_num = num)
		{
		printf("\n电脑开始取石子...\n电脑取了 %d 个", comp_num);
		num = 0;
		lose();
		}
		else goto computer;
	}


return 0;
}
