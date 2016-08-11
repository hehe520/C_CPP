#include <iostream>
#include <fstream>
using namespace std;

// -------fstream 不支持中文-------

int main()
{
	ofstream out;

	// ios::out 输出, ios::app 追加方式
	out.open("C:\\123.txt", ios::out | ios::app);
	if (out)
	{
		char *s = "test";
		int i = 100;

		out << "caokun" << endl;
		out << s << endl;
		out << i << endl;
		out.close();
	}

	// 构造的时候可以直接打开
	// 不指定位置，默认在同一个目录下
	ofstream out2("456.txt", ios::out);
	if (out2)
	{
		out2 << "123456" << endl;
		out2.close();
	}
	else cout << "open error!" << endl;


	// 文件读取流
	ifstream in;
	in.open("c:\\789.txt", ios::in);
	if (in)
	{
		char str[100];

		// 读取整个文件
		while (1)
		{
			in >> str;
			if (!in) break;		// in 为 0 就读取完了
			cout << str << endl;
		}
		in.close();
	}
	else cout << "open error!" << endl;


	// 读取写入合并
	fstream io("c:\\123.txt", ios::in | ios::out);
	if (io)
	{
		char str[100];
		// 读取
		while (1)
		{
			io >> str;
			if (!io) break;
			cout << str << endl;
		}
	}
	else cout << "open error!" << endl;

	return 0;
}
