// 带指针实验
#include <iostream>
using namespace std;

class test
{
public:
	test(const test &m);
	test(int a=0, int b=0);
	~test();
	void input(int, int);
	void show();
private:
	int x;
	int y;
};

void test::show()
{
	cout << x << endl;
	cout << y << endl;
}

void test::input(int a, int b)
{
	x = a;
	y = b;
}

test::~test()
{
	cout << "调用了析构.." << endl;
}

test::test(int a, int b)
{
	x = a;
	y = b;
	cout << "调用了普通构造.." << endl;
}

test::test(const test &m)
{
	x = m.x;	// 私有成员在拷贝构造里可以访问
	y = m.y;
	cout << "调用了拷贝构造.." << endl;
}

void fun(test p)
{
	cout << "进入到fun函数..." << endl;
}

test fun2(void)
{
	test k(100, 100);
	return k;
}

int main(void)
{
	test t;
	t.show();

	test t2(1,1);
	t2.show();

	// 赋值调用
	test t3(t2);
	t3.show();

	// 实参时调用
	cout << "准备进入fun函数..." << endl;
	fun(t3);

	// 返回时调用
	test d;
	cout << "准备执行fun2..." << endl;
	d = fun2();
	cout << "退出了fun2..." << endl;

	return 0;
}