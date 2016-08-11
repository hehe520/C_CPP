#include <stdio.h>
#include <string.h>
#define MAX 3

typedef struct st
{
	int num;
	int age;
	char name[10];
} STU;

void print(STU *ps)
{
	int i;

	for (i=0; i<MAX; i++)
	{
		printf("num = %d,  age = %d,  name = %s\n",
			ps->num, ps->age,  ps->name);
		ps++;
	}  //output
}

int main(void)
{
	int lenth = 0;
	FILE *in  = NULL;
	FILE *out = NULL;
	STU s[MAX];
	int i;

	memset(s, 0, MAX*sizeof(STU));
	
/*	//输入学生信息
	for (i=0; i<MAX; i++)
	{
		s[i].age = i;
		s[i].num = i;
		sprintf(s[i].name, "吴佳颖 %d", i); 
	}

	//  保存学生成绩数据
	out = fopen("c:\\student.dat", "wb");
	if (out != NULL)
	{
		fwrite(s, sizeof(STU), MAX, out);
		fclose(out);
	}
*/
	//  读取学生成绩数据
	in = fopen("c:\\student.dat", "rb");
	if (in != NULL)
	{
		for (i=0; i<MAX; i++)
		{
		//	rewind(in);
		//	fseek(in, 0, SEEK_SET);
			fread(s+i, sizeof(STU), 1, in);
		}
		lenth = ftell(in);
		printf("lenth = %d Byte\n", lenth);
		fclose(in);
	}

	print(s);

	return 0;
}
/*
len = ftell(fp);
ftell() 内部指针与绝对指针的差值，就是离文件开头的距离，
就是当前到了什么地方了，

fseek(in, 0, SEEK_SET);
相当与rewind(fp);
*/
