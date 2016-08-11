#include <stdio.h>

int g_num;

int get_first_num(int n, int i)
{
	int r;
	switch (i)
	{
	case 1 : {r = g_num; break;}
	case 2 : {r = g_num/10; g_num %= 10; break;}
	case 3 : {r = g_num/100; g_num %= 100; break;}
	case 4 : {r = g_num/1000; g_num %= 1000; break;}
	case 5 : {r = g_num/10000; g_num %= 10000; break;}
	}
	return r;
}

int main(void)
{
	int flag=0, num2, num3, i=0;

	do {
		if (flag) printf("\n输入错误!\n");
		printf("请输入十万以内的正数___");
		scanf("%d",&num2);
		fflush(stdin);
		flag = 1;
	}
	while (num2<=0 || num2>=99999);

	g_num = num3 = num2;   //备份 num2
	
	while (num2 != 0)
	{
		i++;
		num2 /= 10;
	}
	printf("\n这是一个 %d 位数\n顺向打出每个数字   ",i);

	for (; i>0; i--)
	{
		printf("%3d",get_first_num(g_num,i));
	}
	
	printf("\n逆向打出每个数字   ");

	i = 0;
	while (num3 != 0)
	{
	i++;
	printf("%3d",num3%10);
	num3 /= 10;
	}
	putchar('\n');

	return 0;
}