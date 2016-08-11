#include <iostream>
using namespace std;

class base
{
public:
	base::base(int x=0, int y=0)
	{
		a = x;
		b = y;
	}
	// 定义虚函数
	virtual void show()
	{
		cout << "base 类 " << a << " , " << b << endl;
	}
private:
	int a;
	int b;
};

class son: public base
{
public:
	son::son(int x=0, int y=0, int z=0, int f=0)
		:base(x, y)
	{
		c = z;
		d = f;
	}
	// 派生类中最好也要加上virtual
	virtual void show()
	{
		cout << "son 类 "  << c << " , " << d << endl;
	}
	void test()
	{
		cout << "son的新增成员" << endl; 
	}
private:
	int c;
	int d;
};

int main()
{
	base *p;
	base b(50, 50);
	son s(1,2,10,10);

	p = &b;
	p->show();
	
	p = &s;		// 用了虚函数后
	p->show();	// p->show 和 s.show 是一样的了
	s.show();

	return 0;
}
