#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 在当前目录产生 num 个单词的文件
int create_str(char *name, int num)
{
	const int max = 60;
	int len;		// 随机长度
	int i, j;
	FILE *out;
	char buf[max+2];

	out = fopen(name, "wt");
	if (!out) return 0;

	srand(time(NULL));
	for (i=0; i<num; i++)
	{
		len = rand() % max + 1;		// 随机长度 <= 60
		for (j=0; j<len; j++)
			buf[j] = rand() % 26 + 'a';
		buf[len] = '\0';
		fputs(buf, out);
		fputc('\n', out);
	}
	getchar();
	getchar();
	fclose(out);
	return 1;
}

int main(void)
{
	int num;

	printf("请输入单词数量: ");
	scanf("%d", &num);
	create_str("input.txt", num);

	return 0;
}