// 密码输入效果

#include <stdio.h>
#include <conio.h>
// conio.h 中的 getch(); 不会输出字符的

int main()
{
	char c = '\0';
	char hide = '*';		// 字符掩码
	char str[100] = {0};	// 输入缓冲区
	int cur = 0;			// 指示
	
	printf("请输入密码：");
	while(1)
	{
		c = getch();
		if (c == 13) break;
		else if (c == 8)	// 退格键
		{
			if (cur)
			{
				putchar('\b');
				putchar(' ');
				putchar('\b');
				str[--cur] = '\0';
			}
		}
		else
		{
			putchar(hide);
			str[cur++] = c;
		}
	}
	printf("\n\n你输入了 %s\n\n", str);

	return 0;
}