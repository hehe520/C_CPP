#include <iostream>
#include <iomanip>		// 操作符头文件

using namespace std;

// 自定义 out 操作符
ostream &out(ostream &oc)
{
	oc << setw(20);
	oc << setiosflags(ios::right | ios::uppercase);
	oc << setfill('*') << dec;
	return oc;
}

// 一般要返回一个引用 &&&&&in
istream &in(istream &i)
{
	i >> hex;
	cout << "请输入一个16进制数";
	return i;
}

int main()
{
	// 使用 ios 成员函数进行格式控制
	cout.width(20);
	cout.setf(ios::right);
	cout << "wujiaying" << endl;
	cout.unsetf(ios::right);	// 取消右对齐设置

	cout.width(30);		// 重新修改宽度
	cout.fill('*');		// 填充符
	cout.setf(ios::left);
	cout << "wujiaying" << endl;
	cout.unsetf(ios::left);

	cout.fill(' ');
	cout.width(50);
	cout.setf(ios::right);
	cout << "test" << endl;
	cout.unsetf(ios::right);

	// 正数显示 + 号
	cout.width(20);
	cout.setf(ios::showpos | ios::right);	// 分隔符进行多个设置
	cout.precision(5);		// 显示 n 个数字
	double pi = 3.14159265358979;
	cout << pi << endl;
	cout.precision(0);
	cout.unsetf(ios::showpos | ios::right);


	// 使用操作符进行格式控制
	int t = 126;
	cout << setw(20) << dec << t << endl;
	cout << setiosflags(ios::uppercase) << hex << t << endl;
	cout << resetiosflags(ios::uppercase) << hex << t << endl;
	cout << out << t << endl;		// 自定义 oc 格式输出操作符
	cin >> in >> t;					// 自定义 in 格式输入操作符
	cout << "对应的10进制是：" << t << endl;

	return 0;
}
