#include <iostream>
#include <string>

using namespace std;

class person
{
public:
	void input(string s, int a, int x);
	void show();
	int num;
	void test(int a);
protected:
	string name;
	int age;
	int sex;
private:
	int privation;
};

void person::test(int a)
{
	cout << a << "person\n";
}

void person::input(string s, int a, int x)
{
	name = s;
	age = a;
	sex = x;
}

void person::show()
{
	cout << name << ", ";
	if (sex) cout << "男, ";
	else cout << "女, ";
	cout << age << endl;
}

class student: public person
{
public:
	void show();
	void test();
	// 子类中的同名函数, 屏蔽父类中的同名函数
};

void student::test()
{
	cout << "student\n";
}

void student::show()
{
	cout << "student" << endl;
}

int main(void)
{
	person p;

	p.input("颖", 19, 0);
	p.show();

	student s;
	s.show();
	s.num = 100;
	s.input("asdf", 20, 1);
	s.person::show();
	s.person::test(10);		// 显示调用 

	return 0;
}