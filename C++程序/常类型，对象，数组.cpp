#include <iostream>
using namespace std;

class student
{
public:
	student::student(int a=0, int b=0, int c=0);
	void input(int a, int b, int c);
	void show();
	void show(student &s) const;	// 常函数
	int updata;
	void test();
	void test2() const;
private:
	float ch;
	float eng;
	float math;
	const int num;
};

student::student(int a, int b, int c)
:ch(a), eng(b), math(c),
num(ch + eng + math)
{
	// 先初始化下面的 ch... 最后初始 num;
	// 或者按成员列表的顺序来初始
//	ch = a;
///	eng = b;
//	math = c;
}

void student::test2() const
{
	cout << "我是常函数" << endl;
//	test():		// 常函数不能调用普通函数
//	updata = 100;	// 也不能更新数据成员
} 

void student::test()
{
	cout << "常对象不能调用我" << endl;
	test2();	// 普通函数可以调用常函数
}

void student::input(int a, int b, int c)
{
	ch = a;
	eng = b;
	math = c;
}

void student::show()
{
	cout << ch << ", " 
		 << eng << ", " 
		 << math << ", " 
		 << num << endl;
	cout << "show的普通函数" << endl;
}

void student::show(student &s) const
{
	cout << ch << ", " 
		 << eng << ", " 
		 << math << ", " 
		 << num << endl;
	cout << "show的常函数" << endl;
//	ch = 100; // 常函数里不能修改数据成员
	s.input(10,20,30);	// 可以调用别的函数
}

int main(void)
{
	student s(100,80,90);

	s.show();
	s.test2();	// 普通成员可以调用常函数

	const student t(10,10,10);

	t.show(s);	// show是常函数
	s.show();

// 常对象的数据不能改, 普通函数也不能调用
//	t.test();	
//	t.input(10,10,10);
//	t.updata = 100;  

	student a[10] = {student(10,10,10), student(20,20,20)};

	a[1].show();

	return 0;
}