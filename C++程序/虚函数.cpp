#include <iostream>
#include <string>

using namespace std;

//     类关系图
//      animal
//     /  |  \
//   cat dog pig

// 基类
class animal
{
public:
	animal()
	{ food = "杂食"; }
	virtual void show()		// 定义虚函数
	{
		cout << "动物食物: " << food << endl;
	}
	// 下面是重载，如 dog 类中所说
	void show(int n)
	{
		cout << "动物数量: " << n << endl; 
	}
private:
	string food;
};

// 公有派生类
class cat: public animal
{
public:
	cat(string &f)
	{ food = f; }
	~cat() {}
	virtual void show()
	{
		cout << "cat 的食物: " << food << endl;
	}
private:
	string food;
};

class dog: public animal
{
public:
	dog(string &f)
	{ food = f; }
	virtual void show()
	{
		cout << "dog 的食物: " << food << endl;
	}
	// 下面这个show不是虚函数，是重载
	// 基类指针不会指向它, 因为基类中没有它
	void show(int n)
	{
		cout << "dog 的数量: " << n << endl;
	}
private:
	string food;
};

class pig: public animal
{
public:
	pig(string &f)
	{ food = f; }
	virtual void show();
private:
	string food;
};

// 类外定义 pig::show, 不用加 virtual
void pig::show()
{
	cout << "pig 的食物: " << food << endl;
}

// 不定义虚函数的类
// 将继续继承 animal 中的 show
class duck: public animal
{
public:
	duck::duck()
	{ cout << "duck create" << endl; }
};

int main(void)
{
	string a = "鱼";
	string b = "骨";
	string e = "肉";

	animal *p;
	animal an;
	cat c(a);
	dog d(b);
	pig g(e);

	// 一个接口 show(); 多种方法
	p = &an;   p->show();
	p = &c;    p->show();
	p = &d;    p->show();
	p = &g;    p->show();
	p->show(123);

	duck du;
	p = &du;   p->show();

	return 0;
}
