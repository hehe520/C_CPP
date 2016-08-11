#include <iostream>
using namespace std;

class base1
{
public:
	virtual void show()		// 虚函数show
	{ cout << "base1" << endl; }
};

class base2
{
public:
	void show()		// 普通函数show
	{ cout << "base2" << endl; }
};

class son: public base1, public base2
{
public:
	virtual void show()
	{ cout << "son" << endl; }
};

int main(void)
{
	base1 *p1;
	base2 *p2;
	son s;

	p1 = &s;   p1->show();   // 虚函数动态调用
	p2 = &s;   p2->show();   // 子类的show被屏蔽，指向基类的show

	return 0;
}