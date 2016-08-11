#include <stdio.h>

// 待分割的文件 name.txt, 和大小 size
// 读一点, 写一点, fread() 每次最大读入的大小有限
// 分多次读取, 直到读满 size 大小, 就新开一个文件
int create_file(char *name, int size)
{
	FILE *in;
	FILE *out;
	int s = 0;		// s = [0..size]
	int an = 0;
	int file_num = 1;	// 分文件标号
	char file_name[100];
	char buffer[1024];		// 临时数据缓冲区(1KB)
	int inc;

	in = fopen(name, "rb");
	if (!in) return 0;

	sprintf(file_name, "%d_%s", file_num++, name);
	out = fopen(file_name, "wb");
	while (1)
	{
		an = fread(buffer, 1, 1024, in);
		if (an == 0) break;
		s += an;			// 累加变量
		if (s > size)		// 一个文件满了
		{
			s -= an;
			inc = size - s;
			fwrite(buffer, 1, inc, out);
			an -= inc;
			fclose(out);

			while (an > size)		// 如果还有多 
			{
				sprintf(file_name, "%d_%s", file_num++, name);
				out = fopen(file_name, "wb");
				
				fwrite(buffer + inc, 1, size, out);
				fclose(out);
				an -= size;
				inc += size;
			}
			if (an > 0)
			{
				sprintf(file_name, "%d_%s", file_num++, name);
				out = fopen(file_name, "wb");

				fwrite(buffer + inc, 1, an, out);
				s = an;
			}
		}
		else fwrite(buffer, 1, an, out);
	}
	if (out) fclose(out);
	fclose(in);
	return 1;
}

int main(void)
{
	long int size;
	char name[100] = "input.txt";

	printf("请输入要分割文件名: ");
	scanf("%s", name);
	printf("请输入每个文件块的大小(Byte): ");
	scanf("%d", &size);
	if (create_file(name, size)) printf("\n分割完毕!\n");
	else printf("\n分割失败, 文件可能不存在\n");

	return 0;
}
