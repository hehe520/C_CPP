/* --------------------
学生成绩管理系统
本程序在 WIN XP VC++6.0 下编译通过
---------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 学生信息结构体
typedef struct
{
	char num[20];		// 学号
	char name[10];		// 姓名
	short int sex;		// 性别
	float chinese;		// 语文
	float math;			// 数学
	float english;		// 英语
	float pe;			// 体育
	float ave;			// 平均成绩
	float sum;			// 总成绩
}student;


void display()	// 界面显示函数
{
	system("color 0e");		// 这句话是界面颜色的
	printf("\n---------学生成绩管理系统\n\n");

	printf("--- 1. 输入学生信息\n\n");
	printf("--- 2. 插入新学生信息\n\n");
	printf("--- 3. 排序并查看\n\n");
	printf("--- 4. 查找\n\n");
	printf("--- 5. 删除\n\n");
	printf("--- 6. 输出\n\n");
	printf("--- 输入序号，执行操作\n");
	printf("--- 输入exit，退出程序：");
}

void back()		// 返回主界面函数
{
	fflush(stdin);
	printf("\n\n--- 按下回车键，回主界面");
	getchar();
	system("cls");		// 系统清屏命令
	display();
}

void num_sort(student s[], int *cur)	// 按学号排序
{
	int i, j;
	int flag;
	student temp;

	for (i=0; i<*cur-1; i++)
	{
		flag = 1;
		for (j=0; j<*cur-1; j++)
		{
			if (strcmp(s[j].num, s[j+1].num) > 0)
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
				flag = 0;
			}
		}
		if (flag) break;
	}
}

void sum_sort(student s[], int *cur)	// 按总成绩排序
{
	int i, j;
	int flag;
	student temp;

	for (i=0; i<*cur-1; i++)
	{
		flag = 1;
		for (j=0; j<*cur-1; j++)
		{
			if (s[j].sum > s[j+1].sum)
			{
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
				flag = 0;
			}
		}
		if (flag) break;
	}
}

int find_num(student s[], char *num, int cur)
{
	int i; 
	
	for (i=0; i<cur; i++)
		if (!strcmp(s[i].num, num))
			return i;
	return -1;
}

int find_name(student s[], char *name, int cur)
{
	int i; 
	
	for (i=0; i<cur; i++)
		if (!strcmp(s[i].name, name))
			return i;
	return -1;
}

void input_each(student s[], int i)	// 输入每一个学生
{
		printf("\n请输入第 %d 个学生信息\n\n", i+1);
		printf("学号: ");
		gets(s[i].num);
		printf("姓名: ");
		gets(s[i].name);
		printf("性别: (0 表示男, 1 表示女)");
		scanf("%d", &s[i].sex);
		printf("语文成绩: ");
		scanf("%f", &s[i].chinese);
		printf("数学成绩: ");
		scanf("%f", &s[i].math);
		printf("英语成绩: ");
		scanf("%f", &s[i].english);
		printf("体育成绩: ");
		scanf("%f", &s[i].pe);
		// 计算总成绩, 平均成绩
		s[i].sum = s[i].chinese + s[i].math + s[i].english + s[i].pe;
		s[i].ave = s[i].sum / 4.0;
}

void input(student s[], int *cur)		// 输入10个
{
	int i;

	system("cls");
	for (i=0; i<10; i++)
	{
		printf("\n--- 输入 10 名学生信息\n");
		fflush(stdin);
		input_each(s, i);
		(*cur)++;
		system("cls");
	}
	num_sort(s, cur);		// 按学号排序存放
	back();
}

void insert(student s[], int *cur)	// 插入
{
	system("cls");
	input_each(s, *cur);
	(*cur)++;
	num_sort(s, cur);	// 不求效率可以再重排序
	back();
}


void print_each(student s[], int i)		// 输出单个学生
{
	printf("%s\t", s[i].num);
	printf("%s\t", s[i].name);
	printf("%s\t", s[i].sex == 1 ? "女" : "男");
	printf("%.1f\t", s[i].chinese);
	printf("%.1f\t", s[i].math);
	printf("%.1f\t", s[i].english);
	printf("%.1f\t", s[i].pe);
	printf("%.1f\t", s[i].ave);
	printf("%.1f\n", s[i].sum);
}

void find(student s[], int cur)		// 查找
{
	int flag;
	char buf[20];
	int addr;

	system("cls");
	printf("\n--- 查找学生信息\n");
	printf("\n--- 1. 按学号查找\n");
	printf("\n--- 2. 按姓名查找\n");
	printf("\n--- 3. 回主界面\n");
	while (1)
	{
		printf("\n--- 请输入要执行的操作: ");
		fflush(stdin);
		scanf("%d", &flag);
		if (flag == 1)
		{
			printf("\n请输入学号: ");
			fflush(stdin);
			scanf("%s", buf);
			addr = find_num(s, buf, cur);
			if (addr == -1) printf("\n--- 没有找到!\n");
			else 
			{
				printf("\n学号\t姓名\t性别\t语文\t数学\t英语\t体育\t平均分\t总成绩\n");
				print_each(s, addr);
			}
		}
		else if (flag == 2)
		{
			printf("\n请输入姓名: ");
			fflush(stdin);
			scanf("%s", buf);
			addr = find_name(s, buf, cur);
			if (addr == -1) printf("\n--- 没有找到!\n");
			else 
			{
				printf("\n学号\t姓名\t性别\t语文\t数学\t英语\t体育\t平均分\t总成绩\n");
				print_each(s, addr);
			}
		}
		else if (flag == 3) break;
		else printf("\nXXX 输入错误");
	}
	back();
}

void del(student s[], int *cur)		// 删除
{
	int flag;
	int addr;
	int i;
	char buf[20];

	system("cls");
	printf("\n--- 删除学生信息\n");
	printf("\n--- 1. 按学号删除\n");
	printf("\n--- 2. 按姓名删除\n");
	printf("\n--- 3. 回主界面\n");
	while (1)
	{
		printf("\n--- 请输入要执行的操作: ");
		fflush(stdin);
		scanf("%d", &flag);
		if (flag == 1)
		{
			printf("\n请输入学号: ");
			fflush(stdin);
			scanf("%s", buf);
			addr = find_num(s, buf, *cur);
			if (addr == -1) printf("\n--- 没有找到!\n");
			else 
			{
				for (i=addr; i<*cur; i++)
					s[i] = s[i+1];
				(*cur)--;
				printf("\n删除成功!\n");
			}
		}
		else if (flag == 2)
		{
			printf("\n请输入姓名: ");
			fflush(stdin);
			scanf("%s", buf);
			addr = find_name(s, buf, *cur);
			if (addr == -1) printf("\n--- 没有找到!\n");
			else 
			{
				for (i=addr; i<*cur; i++)
					s[i] = s[i+1];
				(*cur)--;
				printf("\n删除成功!\n");
			}
		}
		else if (flag == 3) break;
		else printf("\nXXX 输入错误");
	}
	back();
}

void output(student s[], int *cur)	// 输出
{
	int i;

	system("cls");
	printf("\n --- 全部学生信息:\n\n");
	printf("学号\t姓名\t性别\t语文\t数学\t英语\t体育\t平均分\t总成绩\n");
	for (i=0; i<*cur; i++)
		print_each(s, i);
	
	back();
}

void sort(student s[], int *cur)		// 排序
{
	int flag;

	system("cls");
	printf("\n--- 1. 按学号排序\n");
	printf("\n--- 2. 按总成绩排序\n");
	fflush(stdin);
	printf("\n--- 请输入要执行的操作: ");
	scanf("%d", &flag);
	if (flag == 1)
	{
		num_sort(s, cur);
		output(s, cur);
	}
	else if (flag == 2)
	{
		sum_sort(s, cur);
		output(s, cur);
	}
	else 
	{
		printf("\n --- 输入错误! \n");
		back();
	}
}

int getnum(char str[])	// 输入检查函数
{
	int buf;
	char s[10] = "exit";

	if (str[0] >= '0' && str[0] <= '9')
	{
		sscanf(str, "%d", &buf);
		return buf;
	}
	else if (!strcmp(str, s)) return -2;
	else return -1;
}

void wait(student s[], int *cur)	// 等待用户操作函数
{
	char str[10];
	int op;
	
	while (1)
	{
		memset(str, 0, 10*sizeof(char));
		fflush(stdin);
		scanf("%8s", str);
		fflush(stdin);
		op = getnum(str);
		if (op>=1 && op<=6)
		{
			switch (op)
			{
			case 1 : input(s, cur);		break;	// 输入
			case 2 : insert(s, cur);	break;	// 插入
			case 3 : sort(s, cur);		break;	// 排序
			case 4 : find(s, *cur);		break;	// 查找
			case 5 : del(s, cur);		break;	// 删除
			case 6 : output(s, cur);	break;	// 输出
			}
		}
		else if (op == -2) exit(0);
		else printf("XXX 输入错误，请重新输入：");
	}
}

int main(void)
{
	student s[30];	// 有 30 个学生
	int cur = 0;	// 0 是使用量

	memset(s, 0, sizeof(s));	// 初始化
	display();		// 显示主界面
	wait(s, &cur);	// 等待用户操作

	return 0;
}

