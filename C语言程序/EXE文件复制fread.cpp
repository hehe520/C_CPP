#include <stdio.h>
#define BUF 1024
int main(void)
{
	FILE *in  = NULL;
	FILE *out = NULL;
	char buf[BUF] = {0};  //缓冲区，也可以动态分配
	int size = 0;
	int num = 0;  // 成功读取的字节数

	in = fopen("c:\\cpp1.exe", "rb");
	out = fopen("c:\\cpp2.exe", "wb");
	if (in != NULL && out != NULL)
	{
		fseek(in, 0, SEEK_END);  //把相对指针移到文件尾，
		size = ftell(in);        //告诉当前位置，即文件大小
		rewind(in);              //把相对指针移到文件首

		while (1)
		{
			num = fread(buf, 1, BUF, in);
			if (num == 0) break;
			fwrite(buf, 1, num, out);
		}

		fclose(in);
		fclose(out);
	}

	return 0;
}
/*
	num = fread(buf, 1, BUF, in);
	// num 为成功从 BUF (1024) 中成功读取到的字节数
	// 1 为每次读取 1字节，操作BUF次

	fwrite(buf, 1, num, out);
	// 将读取到的字节写入，成功读取了num字节，
	// 每次只写入一个字节

	把 in 的内容移到 buffer 缓冲区，
	缓冲区大小 BUF = 1024 字节
	再把缓冲区的数据复制到 out 中
*/
