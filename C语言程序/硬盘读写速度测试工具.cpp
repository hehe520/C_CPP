#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#define SIZE 1024
#define PPATH "c:\\~test2.tmp"
#define WPATH "c:\\~test.tmp"

int main(void)
{
	FILE *out = NULL;
	FILE *in  = NULL;
	char buffer[SIZE];  // 读取数据缓冲区
	int i;
	char c = 0;         // 用户按键
	char buf = 'f';     // 写入的数据
	int sn = 0;         // 一共写入KB
	int t1, t2, now, beg;  // 记时变量
	int first = 1;
	float ave, pos, tmp;  // 数据变量
	int an, an2;          // 计算时间的
	
	system("color 0a");
	printf("\n硬盘读写速度测试工具\tBy caokun\n\n");
	printf("按下回车键开始测试");
	scanf("%c", &c);
	printf("\n");
	if (c == '\n')
	{
		out = fopen(WPATH, "wb");
		if (out != NULL)
		{
			printf("------开始测试写入速度...\n\n");
			an = 0;
			beg = t1 = clock();
			for (i=0; i<(200*(SIZE)); i++)
			{
				sn += fwrite(&buf, sizeof(char), SIZE, out);
				// 开始写入,,下面是时间,大小的计算
				now = clock();
				if ((now-beg > 400) || first || i == (200*SIZE)-1)
				{
					first = 0;
					tmp = (float)(now - beg)/1000;
					if (tmp < 0.000001) tmp = (float)0.000001;
					ave = ((float)(sn-an)/(SIZE*SIZE)) / tmp;
					pos = (float)sn / (SIZE*SIZE*2);
					printf("当前写入速度：%.2f MB/s \t测试进度：%.2f%%    \r", ave, pos);
					beg = clock();
					an = sn;
				}
			}
			fclose(out);
			t2 = clock();
			ave = (sn/(SIZE*SIZE)) / ( (float)(t2 - t1)/1000 );
			printf("\n\n平均写入速度：%.2f MB/s\t用时：%.2f秒\n", ave, (t2-t1)/1000.0);
			
			// 初始化数据
			out = NULL;
			an2 = an = sn = 0;
			first = 1;

			printf("\n\n------开始测试读取速度...\n\n");
			out = fopen(WPATH, "rb");
			in = fopen(PPATH, "wb");
			if (out != NULL && in != NULL)
			{
				beg = t1 = clock();
				for (i=0; ; i++)
				{
					sn += (an = fread(buffer, sizeof(char), SIZE, out));
					if (an != 0)
					{
						fwrite(buffer, sizeof(char), an, in);
					}
					now = clock();
					if ((now-beg > 400) || first || i == (200*SIZE)-1)
					{
						first = 0;
						tmp = (float)(now - beg)/1000;
						if (tmp < 0.000001) tmp = (float)0.000001;
						ave = ((sn-an2)/(SIZE*SIZE)) / tmp;
						pos = (float)sn / (SIZE*SIZE*2);
						printf("当前读取速度：%.2f MB/s \t测试进度：%.2f%%    \r", ave, pos);
						beg = clock();
						an2 = sn;
					}
					if (an == 0) break;
				}
				fclose(in);
				fclose(out);
				t2 = clock();
				ave = (sn/(SIZE*SIZE)) / ( (float)(t2 - t1)/1000 );
				printf("\n\n平均读取速度：%.2f MB/s\t用时：%.2f秒\n", ave, (t2-t1)/1000.0);
			}
		}
		else
		{
			printf("\n读取错误，程序将关闭！\n");
		}
	}
	remove(PPATH);
	remove(WPATH);
	printf("\n\n测试完毕!\n");
	getchar();
	return 0;
}
