#include <iostream>
#include <cmath>

using namespace std;

const double EPS = 1e-100;	// 误差

double chu(double a, double b)
{
	if (fabs(b - 0) < EPS) throw b;
	return a / b;
}

int main()
{
	// tyr-catch 结构可以嵌套
	try
	{
		cout << chu(10, 3) << endl;
		cout << chu(10, 0) << endl;		// 遇到错误直接退出 try
		cout << chu(10, 4) << endl;		// 后面的 try 不再执行
		cout << chu(11, 0) << endl;
	}
	catch (int)
	{
		cout << "int 除数不能为 0" << endl;
	}
	catch (double)
	{
		cout << "double 除数不能为 0" << endl;
	}
	catch (...)		// 捕获所有异常信息
	{ cout << "错误！" << endl; }

	cout << "continue..." << endl;	// 继续执行后面语句

	return 0;
}
