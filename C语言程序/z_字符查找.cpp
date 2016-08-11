#include <stdio.h>
int main(void)
{
	char str[] = "1234567890abc";
	char *p;
	char find = 0;

	find = getchar();

	for (p=str; *p && *p != find; p++);
	//*p还没到\0, *p还不是find, 
	if (*p == 0) printf("on\n");
	else printf("yes\n");

return 0;
}