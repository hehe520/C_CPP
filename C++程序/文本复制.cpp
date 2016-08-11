#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fin("c:\\a.txt", ios::in);
	if (fin)
	{
		ofstream fout("c:\\b.txt", ios::out);
		if (fout)
		{
			char b;
			while (1)
			{
				fin.get(b);
				if (!fin) break;
				fout << b;
				cout << b;
			}
			fout.close();
		}
		fin.close();
	}

	return 0;
}