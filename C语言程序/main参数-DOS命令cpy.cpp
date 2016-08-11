#include <stdlib.h>
#include <stdio.h>

void quit(void)
{
	printf("error!\n");
	exit(0);
}

int main(int argc, char *argv[])
{
	FILE *in;
	FILE *out;
	FILE *tryout;
	char c = 0;
	
	if (argc >= 2)  //参数要等于2才可以进行复制
	{
		in = fopen(argv[1], "r");
		if (in == NULL)
		{
			printf(argv[1]);
			printf(" 文件不存在\n");
			quit();
		}
		else 
		{
			tryout = fopen(argv[2], "r");
			if (tryout != NULL)
			{
				//目标文件存在，
				printf(argv[2]);
				printf("文件存在!，是否覆盖 y/n? ");
				fflush(stdin);
				fclose(tryout);  //及时关闭
				c = getchar();
				if (!(c == 'Y' || c == 'y'))
				{
					exit(0);
				}
			}

			out = fopen(argv[2], "w");
			if (out != NULL)
			{
				//复制ascll文件
				while (1)
				{
					c = fgetc(in);
					if (c == EOF) break;
					fputc(c, out);
				}
				fclose(in);
				fclose(out);
				printf("复制成功！\n");
			}
			else quit();
		}
	}
	else quit();
	
	return 0;
}
/*
在DOS下输入参数
例如copy test.txt d:\out.txt
-----------------------------
查看原文件在不在
查看目标文件有没有重名
才开始复制文件
*/