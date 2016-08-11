#include <iostream.h>

class complex
{
public:
	complex()
	{ real = 0;  imag = 0; }
	complex(double r)
	{ real = r;   imag = 0; }
	complex(double a, double b)
	{ real = a;  imag = b; }
	friend ostream &operator << (ostream &out, complex &a);
	// 类型转换函数，将本类 转为 基本的数据类型
	operator double()   // 转 double 型
	{
		return real;	// 返回一个double型
	}
	// 类似可以 operator int() { return int(real); }
private:
	double real;
	double imag;
};

ostream &operator << (ostream &out, complex &a)
{
	out << a.real;
	if (a.imag >= 0) out << "+";
	cout << a.imag << "i";
	return out;
}

int main()
{
	complex c1(4.2, 5);
	complex c2(2.3, 1);
	cout << c1 << endl;

	double d;
	d = c1;				// 隐式转换
	cout << d << endl;
	d = double(c1);		// 显示转换
	cout << d << endl;

	int i;
	i = int(c1);   cout << i << endl;

	complex c3;
	c3 = c1 + c2;
	cout << c3 << endl;
	// 先找 operator + (), 找不到
	// 将 c1 c2 通过 operator double() 转为 double 型
	// 再通过 complex(double) 转为 complex 赋给 c3

	return 0;
}
