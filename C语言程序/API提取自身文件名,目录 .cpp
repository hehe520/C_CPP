#include <stdio.h>
#include <windows.h>
#include <string.h>

int main(void)
{
	char buffer[MAX_PATH] = {0};
	char dir[MAX_PATH];

	if (GetModuleFileName(NULL, buffer, MAX_PATH))
	{
		printf("%s\n", buffer);
	}

	if (GetCurrentDirectory(MAX_PATH, dir))
	{
		printf("%s\n", dir);
	}

	return 0;
}