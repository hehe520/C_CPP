#include <stdio.h>

int s[30][30] = {0};
int n;

int go(int x, int y)
{
	if ((x>=0 && y>=0)
		&& (x<n && y<n)
		&& (s[x][y] == 0))
		return 1;
	else return 0;
}

int main(void)
{
	int k, i, j;
	int direct;

	direct = i = j = k = 0;
	scanf("%d",&n);

	for (k=1; k<=n*n; k++)
	{
		s[i][j] = k;

		switch(direct%4)
		{
		case 0 : {if (go(i, j+1)) j++;
				else {direct++; i++;} break;}
		case 1 : {if (go(i+1, j)) i++;
				else {direct++; j--;} break;}
		case 2 : {if (go(i, j-1)) j--;
				else {direct++; i--;} break;} 
		case 3 : {if (go(i-1, j)) i--;
				else {direct++; j++;} break;}
		}
	}

	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			printf("%4d",s[i][j]);
		}
		printf("\n\n");
	}

return 0;
}
/*
0 is right, 1 is down, 2 is left, 3 is up
思路分析，用个画笔(i, j)
用个go(x, y)去探路，
direct 控制方向，
*/