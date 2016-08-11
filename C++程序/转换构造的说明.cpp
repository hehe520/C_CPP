#include <iostream.h>

class point
{
public:
	// 如果用了转换构造函数
	// 就不能用带有默认参数的构造函数
	// 因为 point(double a=0, double b=0) 与 point(double a)
	// 当 point(3.14) 不知道调用谁，产生二义性
	point(double a, double b)
	{ x = a;   y = b; }
	point(double a)
	{ x = a;   y = 0; }
	point()
	{ x = 0;   y = 0; }
	friend bool operator < (point &p1, point &p2);
	bool operator > (point &p1)
	{
		if (x > p1.x) return true;
		else return false;
	}
private:
	double x;
	double y;
};

bool operator < (point &p1, point &p2)
{
	if (p1.x < p2.x) return true;
	else return false;
}

int main()
{
	point a(1, 2);
	point b(2, 3);

	// 隐式调用友元 <
	if (a < b) cout << "a < b";
	else cout << "a >= b";
	cout << endl;
	
	// 类型转换，转到本类
	if (a < point(2.2)) cout << "a < b";
	else cout << "a >= b";
	cout << endl;

	// 显示调用
	if (operator < (a, b)) cout << "a < b";
	else cout << "a >= b";
	cout << endl;

	// 类成员重载
	if (b > a) cout << "b > a";
	else cout << "b <= a";
	cout << endl;

	// 显示调用
	if (b.operator > (a)) cout << "b > a";
	else cout << "b <= a";
	cout << endl;

	return 0;
}
