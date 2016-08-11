#define LOCAL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float s[5][5] = {0.0f};

void print(void)
{
	int i, j;
	putchar('\n');
	printf("学号   数学   C语言\t英语\t平均成绩\n");
	for (i=0; i<5; i++)
	{
		for (j=0; j<5; j++)
		{
			if (j==0) printf("%.0f", s[i][j]);
			else printf("%9.1f", s[i][j]);
		}
		putchar('\n');
	}
}

int main(void)
{
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif

	float sum = 0.0f, tep;
	int i, j, k, flag;
	char cla[10] = "平均成绩";

	for (i=0; i<5; i++) 
	{
		s[i][0] = (float)i+1;
	}
	for (i=0; i<5; i++)
	{
		for(j=1; j<4; j++)
		{
			if (j==1) strcpy(cla,"数学");
			if (j==2) strcpy(cla,"C语言");
			if (j==3) strcpy(cla,"英语");

			printf("请输入第 %d 位学生的%s成绩",i+1,cla);
			scanf("%f", &s[i][j]);
			sum += s[i][j];
			putchar('\n');
		}
		s[i][4] = sum/3;
		sum = 0.0f;
	}
	print();
	printf("\n\n排序后\n");
	for (j=0; j<5; j++)
	{
		flag = 1;
		for (i=0; i<4; i++)    //i是第i为同学
		{
			if (s[i][4] < s[i+1][4])
			{
				tep = s[i][4];
				s[i][4] = s[i+1][4];
				s[i+1][4] = tep;
				flag = 0;
				for (k=0; k<=3; k++)
				{
					tep = s[i][k];
					s[i][k] = s[i+1][k];
					s[i+1][k] = tep;
				}
			}
		}
		if (flag == 1) break;
	}
	print();

return 0;
}
