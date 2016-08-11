#include <stdio.h>
int main(void)
{
	char str[] = " i am a good    boy ";
	char *scan;
	char *c;

	puts(str);
	for (scan=str; *scan!=0; scan++)
	{
		if (*scan == ' ')
		{
			c = scan;
			for (; *scan!=0; scan++)
			{
				if (*scan != ' ')
				{
					*c = *scan;
					*scan = ' ';
					break;
				}
			}
			c++;
			scan = c-1;
		}
	}
	*scan = '\0';
	puts(str);

return 0;
}