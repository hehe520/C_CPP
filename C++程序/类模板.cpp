#include <iostream>
using namespace std;
// vc++6.0 下要用 iostream.h

// 自定义的类型
class node
{
public:
	node() 
	{ data = 0; }
	node(int r)
	{ data = r; }
	int data;
	int *next;
	friend ostream &operator << (ostream &out, node &p);
};

ostream &operator << (ostream &out, node &p)
{
	out << p.data;
	return out;
}


// 类模版
template <typename type>
class point
{
public:
	point()
	{ x = type(0);  y = type(0); }
	point(type a ,type b)
	{ x = a;   y = b; }
	void show()		// 类内定义成员
	{
		cout << "(";
		cout << x << "," << y;
		cout << ")" << endl;
	}
private:
	type x;
	type y;
};

/* 如果是要类外定义 point::show()
template <typename type>
void point<type>::show()
{
	// continue...
}*/

// 类模板不能重载，但是可以多个参数类型
// 参数类型可以不全部用上，可以试验加上 typename type3
template <typename type1, typename type2>
class test
{
public:
	test();
	test(type1 a ,type2 b)
	{ x = a;   y = b; }
	void show();		// 类外定义成员
	type1 func(type1 a);
private:
	type1 x;
	type2 y;
};

// 类外定义成员先要进行模板声明
template <typename t1, typename t2>
void test<t1, t2>::show()
{
	cout << "(";
	cout << x << "," << y;
	cout << ")" << endl;
}

// 类名<参数类型...>::成员函数名(参数列表...)
template <typename type1, typename type2>
type1 test<type1, type2>::func(type1 a)
{
	cout << a << endl;
}

// 类外定义构造函数
template <typename type1, typename type2>
test<type1, type2>::test()
{ x = type1(0);  y = type2(0); }


int main()
{
	// 把类名 point 看作函数名，把数据类型int看作参数 
	point<int>p1;
	point<int>p2(1, 2);
	p1.show();
	p2.show();

	point<double>p3(3.2, 5.6);
	p3.show();

	point<char>p4('c', 'k');
	p4.show();

	// 如果是自定义的类型
	// 要自己写 构造转换函数，<< 运算符重载
	point<node>n1(10, 13);
	n1.show();

	// 多参数类型的类模板
	test<float, char>p5(3.14f, 'w');
	p5.show();
	test<char*, int>p6("wujiaying", 3);
	p6.show();

	return 0;
}

