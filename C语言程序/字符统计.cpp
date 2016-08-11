#include <stdio.h>
int main(void)
{
	char str[60] = {0};
	int i, flag = 0, count = 0;
	
	printf("单词统计\n请输入一组字符\n");
	gets(str);

	for (i=0; str[i]!=0; i++)
	{
		if (((str[i]>='a') && (str[i]<='z'))
			|| ((str[i]>='A') && (str[i]<='Z')))
		{
			if (flag == 0) count++;
			//flag=0说明前一个不是字母，但现在是了，
			flag = 1;
		}
		else flag = 0;
	}
	printf("\n单词数 %d\n",count);

return 0;
}