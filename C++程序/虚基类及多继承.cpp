#include <iostream>
using namespace std;

//   继承关系图
//
//     first
//       |
//      base    base2   base
//      /  \    /       /
// father  mother    other
//      \  /          /
//     child ---------

class first
{
public:
	first::first()
	{ cout << "first 创建" << endl; }
	first::~first()
	{ cout << "first 销毁" << endl; }
};

class base: public first
{
public:
	// 条件构造, 或者使用默认参数，
	// 则 father 中可以不写 base() 的构造
	base::base(int n)
	{
		cout << "base 创建 ";
		data = n;
		cout << " data = " << data << endl;
	}
	base::~base()
	{ cout << "base 销毁" << endl; }
protected:
	int data;
};

class base2
{
public:
	base2::base2(int n)
	{ cout << "base2 创建" << endl; }
	base2::~base2()
	{ cout << "base2 销毁" << endl; }
};

// 使用 virtual 表示，所有用了 virtual 的子类
// 基类公用一个空间，也就是 mother 中改了 data = 100
// father 中也改了，
// 去掉 virtual 可看区别

class father: protected virtual base
{
public:
	father::father(int n): base(n+10) // 不是最远的子类构造，忽略base(n+10)
	{ cout << "father 创建" << endl; }
	father::~father()
	{ cout << "father 销毁" << endl; }
	void set_data()
	{
		data = 10;
	}
};

// base2 不是虚基类，所以构造虚基类 base，后构造 base2
// 即使 base2 在前面声明也先构造 base
class mother: public base2, virtual protected base
{
public:
	mother::mother(int n): base2(100), base(n+100)
	{ cout << "mother 创建" << endl; }
	mother::~mother()
	{ cout << "mother 销毁" << endl; }
	void set_data()
	{
		data = 100;
	}
};

class other: public base
{
public:
	other::other(int n): base(n)
	{ cout << "other 创建" << endl; }
	other::~other()
	{ cout << "other 销毁" << endl; }
};

class child: protected father, protected mother, protected other
{
public:
	// base(1) 虚基本只接受最远的条件构造
	child::child(): base(1), father(10), mother(100), other(123)
	{ cout << "child 创建" << endl; }
	child::~child()
	{ cout << "child 销毁" << endl; }
	void show_data()
	{
		father::set_data();
		mother::set_data();
		cout << "father.data = " << father::data << endl;
		cout << "father.data = " << mother::data << endl;
		cout << "other.data = " << other::data << endl;
	}
};

int main(void)
{
	child c;
	cout << endl;

	c.show_data();

	cout << endl;
	return 0;
}

