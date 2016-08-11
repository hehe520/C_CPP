#include <iostream>
#include <fstream>
using namespace std;

// get put 读写一个个字符

int main()
{
	// get  put 
	ofstream fout("c:\\123.txt", ios::binary | ios::app);

	if (fout)
	{
		char a = 'a';
		for (int i=a; i<='z'; i++)
			fout.put(i);
		fout << endl;
		fout.close();
	}

	ifstream fin("c:\\123.txt", ios::binary);

	if (fin)
	{
		char c;
		while (fin.get(c))		// get 读取失败返回 0
			cout << c;
		cout << endl;
		fin.close();
	}

	// read  write
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	ofstream out("c:\\data.dat", ios::binary | ios::out);
	if (!out) abort();
	
	// 分 10 次写入, 
	for (int i=0; i<10; i++)
		out.write((char *)( a + i ), sizeof(int));	// 写入二进制数据
	out.close();
	
	int b[10];
	ifstream in("c:\\data.dat", ios::binary | ios::in);
	if (!in) abort();
//	for (int i=0; i<10; i++)
	// 也可以一次性写入 10 * sizeof(int)
	in.read((char*)(&b),10 * sizeof(int));
	for (int i=0; i<10; i++) cout << b[i];
	cout << endl;
	in.close();

	return 0;
}
