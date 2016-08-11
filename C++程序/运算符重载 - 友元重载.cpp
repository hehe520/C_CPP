#include <iostream.h>	// 带 .h 的才支持友元重载

// 复数
class complex
{
public:
	complex(double x=0, double y=0)
		:real(x), imag(y) {}
	void show()
	{
		cout << real;
		if (imag < 0) cout << imag << "i" << endl;
		else cout << "+" << imag << "i" << endl;
	}
	// 类外定义，用友元函数
	friend complex operator + (complex &a, complex &b);
	friend complex operator - (complex &a, complex &b);   // 减号
	friend complex operator - (complex &a);				// 负号
	friend complex operator -- (complex &a);
	friend complex operator -- (complex &a, int);
private:
	double real;
	double imag;
};

complex operator + (complex &a, complex &b)
{
//  普通做法
//	complex tmp;
//	tmp.real = a.real + b.real;
//	tmp.imag = a.imag + b.imag;
//	return tmp;

//  complex *p = new complex(1, 2);
//  高效做法, 构造一个无名临时对象
	return complex(a.real + b.real, a.imag + b.imag);
}

complex operator - (complex &a, complex &b)
{
	return complex(a.real - b.real, a.imag - b.imag);
}

// 为了能连续写表达式，所以返回complex，而不是void
complex operator -- (complex &a)     // 前缀的 --c 重载
{
	a.real = a.real - 1;
	a.imag = a.imag - 1;
	cout << "前缀调用--" << endl;
	return a;
}

// 后缀的 c--, 参数要加个无用的 int 来区别
complex operator -- (complex &a, int)
{
	a.real = a.real - 1;
	a.imag = a.imag - 1;
	cout << "后缀调用--" << endl;
	return a;
}

complex operator - (complex &a)
{
	a.imag = -a.imag;
	a.real = -a.real;
	return a;
}

int main(void)
{
	complex c1(1.2, 3.4);
	complex c2(3.4, -1.1);
	complex c3;

	cout << "c1 = ";   c1.show();
	cout << "c2 = ";   c2.show();
	cout << "c1 + c2 = ";
	c3 = c1 + c2;       c3.show();
	c3 = operator + (c1, c2);		// 显式调用
	cout << "c1 + c2 = ";  c3.show();

	cout << "c1 - c2 = ";
	c3 = c1 - c2;		c3.show();

	--c3;
	cout << "c3 = ";   c3.show();
	c3 = operator -- (c3);			// 显式调用
	cout << "c3 = ";   c3.show();

	c3--;
	cout << "c3 = ";   c3.show();
	c3 = operator -- (c3, 0);		// 显式后缀调用
	cout << "c3 = ";   c3.show();
	cout << endl;

	c3 = -c3;
	cout << "c3 = ";   c3.show();
	c3 = operator - (c3);
	cout << "c3 = ";   c3.show();

	complex a(2, 2);
	complex b(6, 6);
	complex c(-4, -4);
	complex sum;
	b--;
	sum = (-a) + b + c;   sum.show();

	return 0;
}
