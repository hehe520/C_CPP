#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	FILE *in, *out;
	char *ipath = "c:\\a.txt";  //原文件
	char *opath = "c:\\aout.txt";   //目标文件
	char c = 0;

	in = fopen(ipath, "r");
	out = fopen(opath, "w");

	if (in != NULL && out != NULL)
	{
		while (1)  //因为是ascll文件，可用EOF
		{
			c = fgetc(in);
			if (c == EOF) break;
			printf("%c", c);
			fputc(c, out);
		}
	}
	else exit(0);
	printf("\n");

	fclose(in);
	fclose(out);
	return 0;
}
