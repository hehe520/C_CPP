#include <iostream>
using namespace std;

int main(void)
{
	int **p = NULL;
	int x, y, j;
	static int num = 0; 

	cin >> x >> y;
	cout << x << "   " << y << endl;
	
	p = new int * [y];
	// ÉêÇëÐÐ£¬ÉêÇëÁÐ
	for (int i=0; i<y; i++)
	{
		p[i] = new int[x];
	}

	for (i=0; i<y; i++)
	{
		for (j=0; j<x; j++)
		{
			p[i][j] = num++;
		}
	}

	for (i=0; i<x; i++)
	{
		for (int j=0; j<y; j++)
		{
			cout << p[i][j] << endl;
		}
	}

	return 0;
}
