#include <iostream.h>

class point
{
public:
	point(double a, double b)
	{ x = a;   y = b; }
	friend ostream &operator << (ostream &out, point &p);
	friend bool operator > (point &p1, point &p2);
private:
	double x;
	double y;
};

// 是 &operator << 返回一个引用
ostream &operator << (ostream &oc, point &p)
{
	oc << "(";
	oc << p.x << "," << p.y;
	oc << ")";
	return oc;
}

// 模版的声明和实现全部都要在头文件中
// 也可用 template <class type>
template <typename type>
type max(type &a, type &b)
{
	return a > b ? a : b;
}

// 多个数据类型, 形参中三个类型必须全部用上
template <typename type1, typename type2, typename type3>
type1 test(type1 a, type2 b, type3 c)
{
	cout << a << "-" << b << "-" << c;
	return a;
}

// 模版与模版的重载
template <typename type>
type max(type &a, type &b, type &c)
{
	bool flag1 = true;
	bool flag2 = true;
	type tmp;

	// 先排序，输出中间那个
	while (flag1 || flag2)
	{
		if (a > b) {tmp = a; a = b; b = tmp;}
		else flag1 = false;
		if (b > c) {tmp = c; c = b; b = tmp;}
		else flag2 = false;
	}
	return b;
}

// 模版与普通函数的重载
float max(float a, float b)
{
	return a > b ? a : b;
}

int main()
{
	int a = 9;
	int b = 4;
	int a1 = 4;
	cout << max(a, b) << endl;
	cout << max(a, b, a1) << endl;	// 重载另一个模版

	double c = 1.2;
	double d = 1.3;
	cout << max(c, d) << endl;

	char e = 'e';
	char f = 'f';
	cout << max(e, f) << endl;

	point g(1.2, 3);
	point h(1.6, 4);
	cout << max(g, h) << endl;		// 自定义类型

	float q = 3.1f;
	float w = 3.2f;
	cout << max(q, w) << endl;		// 与普通函数重载

	char *str = "abcdefg";
	int s = 12;
	double s2 = 3.456;
	cout << test (s, s2, str) << endl;
	// 多个数据类型

	return 0;
}

// 重载 >
bool operator > (point &p1, point &p2)
{
	if (p1.x > p2.x) return true;
	else return false;
}
