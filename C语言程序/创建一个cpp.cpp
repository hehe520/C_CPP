#include <stdio.h>

int exist(char *f)
{
	FILE *test = NULL;
	int flag;
	
	test = fopen(f, "rb");
	if (test == NULL) flag = 0;
	else 
	{
		flag = 1;
		fclose(test);
	}

	return flag;
}

int main(void)
{
	FILE *p;
	int i;
	char str[20] = {0};

	for (i=1; i<200; i++)
	{
		sprintf(str, "cpp%d.cpp", i);
		if (!exist(str))
		{	
			p = fopen(str, "wb");
			fclose(p);
			break;
		}
	}

	return 0;
}