#define SIZE 1024
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
	FILE *in  = NULL;
	FILE *out = NULL;
	char buf[SIZE] = {0};
	int size = 0;
	int num = 0;
	int sum = 0;
	int t1, t2, beg, cur;
	float ave, now;
	int first = 1;

	beg = t1 = clock(); 
	in = fopen("c:\\[SumiSora][Angel_Beats][13][GB].rmvb", "rb");
	out = fopen("c:\\复件1.rmvb", "wb");

	if (in != NULL && out != NULL)
	{
		fseek(in, 0, SEEK_END);
		size = ftell(in);
		printf("filesize = %d\n", size);
		rewind(in);

		while (1)
		{
			num = fread(buf, 1, SIZE, in);
			sum += num;
			cur = clock();
			if ( (cur - beg)>400 || first || num != SIZE)
			{
				first = 0;
				beg = clock();
				now = ((float)sum/size)*100;
				ave = ((sum)/((float)(cur - t1)/1000)) / (1024*1024);
				printf("当前已复制  %.2f%%  平均速度 %.2f MB/s\t\r", now, ave);
			}
			if (num <= 0) break;
			fwrite(buf, 1, num, out);
		}
		printf("复制完毕！\n");
		fclose(in);
		fclose(out);
	}
	t2 = clock();

	printf("用时：%.3f秒\n\n", ((t2-t1)/1000.0));

	return 0;
}