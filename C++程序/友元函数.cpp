#include <iostream>
using namespace std;

class teacher;
class student;

class teacher
{
public:
	void input(int n);
	friend void show(teacher &m);
	// 友元函数,可以在多个类里定义
	int getstore(student &m);
private:
	int num;
	void test();
};

class student
{
public:
	student();
	void input(int n);
	friend void show(student &m);
	// 友元函数
	friend int teacher::getstore(student &m);
	// 其他类的来访问改类的成员
	friend teacher;
	// 老师类中的所有函数都可访问私有成员
private:
	int store;
};

student::student()
{
	store = 0;
}

int teacher::getstore(student &m)
{
	return m.store;	// 私有的数据
}

void teacher::input(int n)
{
	num = n;
}

void student::input(int n)
{
	store = n;
}

void show(student &m)
{
	cout << m.store << endl;
	// 友元 可以访问私有成员
}

void show(teacher &m)	// show 重载
{
	cout << m.num << endl;
	m.input(10);
	m.test();	// 友元函数可以调用私有函数
}

void teacher::test()
{
	cout << "私有函数" << endl;
}

int main(void)
{
	student s;
	s.input(100);

	teacher t;
	t.input(10);

	show(s);
	show(t);
	// 友元函数不能通过对象访问，
	// 直接调用即可
	
	cout << t.getstore(s) << endl;
	// 看看 s 同学的分数

	return 0;
}
