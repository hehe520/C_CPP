#include <iostream>
using namespace std;

// 类模板的嵌套, 动态创建

template <typename type>
class math
{
public:
	math(type t=0);
	type max(type &a, type &b);
	void show()
	{ cout << "data = " << data << endl; }
private:
	type data;
};

// 类外定义 max(), math()
template <typename type>
type math<type>::max(type &a, type &b)
{
	return a > b ? a : b;
}

template <typename type>
math<type>::math(type t)
{ data = t; }


template <typename type>
class test: public math<type>	// 继承类模板
{
public:
	test(type a, type b): math<type>(b)	// 基类构造时也要 math<type>
	{ data = a; }
	void show();
	math<type> obj1;		// 类模板的嵌套
private:
	type data;
};

template <typename type>
void test<type>::show()
{
	cout << "data = " << data << endl;
}

int main()
{
	// 和以前类的使用一样，只是所有的 math 变成 math<int> 
	// 把 math<...> 看成 math 即可
	math<int> *p = new math<int> (55);
	p->show();
	delete p;

	test<char> t('c', 'k');
	t.show();				// c
	t.math<char>::show();	// k
	t.obj1.show();			// NULL
	// 基类的show与子类的show重名，必须显示调用 math<char>::show()

	test<double> t2(3.14, 1.23);
	t2.show();				  // c
	t2.math<double>::show();  // k
	t2.obj1.show();			  // NULL

	return 0;
}
