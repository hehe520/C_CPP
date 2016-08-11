#include <iostream>
#include <fstream>
using namespace std;

// 二进制文件随机读写
// 计算文件大小

int main()
{
	// 写入文件
	ofstream out("c:\\123.dat", ios::binary | ios::out);
	if (!out) abort();
	double p[3] = {5,2,0};
	out.write((char *)p, 3 * sizeof(double));
	out.close();

	ifstream in("c:\\123.dat", ios::binary | ios::in);
	if (!in) abort();

	// 计算文件大小
	__int64 an;
	in.seekg(0, ios::end);		// 0 是位移量，ios::end去到文件最后，
	an = in.tellg();
	cout << "文件大小: " << an  << " 字节" << endl;

	// 随机读取一个
	in.seekg(sizeof(double), ios::beg);	// seekg(移动的字节数，相对位置)
	double a;
	in.read((char *)&a, sizeof(double));	// 写到 &a 这个地址里
	cout << a << endl;
	in.close();

	return 0;
}