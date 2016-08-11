#include <iostream>
using namespace std;

// 在用基类指针动态创建子类对象，
// 释放时，子类没有被释放
// 定义基类的虚析构函数，可以解决此问题
// 一虚百虚

class base
{
public:
	base()
	{ cout << "base 创建" << endl; }
	virtual ~base()
	{ cout << "base 释放" << endl; }
private:
	// to be continue...
};

class son: public base
{
public:
	son()
	{ cout << "son 创建" << endl; }
	virtual ~son()
	{ cout << "son 释放" << endl; }
private:
	// to be continue...
};

int main(void)
{
//	son *p;  // 用子类指针正常
//	p = new son;
//	delete p; 

	// 用基类指针，new创建子类对象，将出错
	base *q = new son;
	delete q;    // 子类没有被释放，定义虚析构函数可解决

	return 0;
}
