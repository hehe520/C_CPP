#include <stdio.h>
int main()
{
	char s[40] = {0};
	int map[27] = {0};
	int i;

	gets(s);
	for (i=0; s[i]!=0; i++)
	{
		map[s[i]-'a']++;
	}
	for (i=0; s[i]!=0; i++)
	{
		if (map[s[i]-'a'] == 1) 
		{
			printf("\n%c\n",s[i]);
			break;
		}
	}

return 0;
}