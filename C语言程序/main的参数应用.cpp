#include <stdio.h>
int main(int argc, char *argv[])
{
	int i; 
	for (i=0; i<argc; i++)
	{
		printf("参数 %d：",i);
		printf(argv[i]);
		printf("\n");
	}
	printf("success! \n");

	return 0;
}
/*
在DOS下 键入 cpp1 参数1 参数2
参数0是本程序的文件名
可以实现程序的自我复制
*/