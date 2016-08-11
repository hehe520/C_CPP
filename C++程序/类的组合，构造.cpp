#include <iostream>
using namespace std;

class student;

class Tgrade
{
public:
	Tgrade::Tgrade(int a=0,int b=0,int c=0);
	Tgrade::~Tgrade();
	float chinese;
	float english;
	float math;
	friend student;
private:
	float sum;	// 看看总分能不能访问
};

class student
{
public:
	student::student(int a=0,int b=0,int c=0);
	// student 中对 Tgrade 进行初始化
	student::~student();
	void showgrade();
	char *name;
private:
	Tgrade grade;
	bool sex;
};

// 这里用grade自身的构造函数，也可以用grade.math = ...;
student::student(int a,int b,int c):grade(a, b, c)
{
	cout << "student constructor\n";
}

Tgrade::Tgrade(int a,int b,int c)
{
	cout << "grade constructor\n";
	chinese = a;
	english = b;
	math = c;
	sum = chinese + english + math;
}

void student::showgrade()	// student要访问Tgrade中的私有
{
	cout << grade.chinese << endl
		 << grade.english << endl
		 << grade.math << endl;
	cout << grade.sum << endl;
}

Tgrade::~Tgrade()
{
	cout << "Tgrade destory\n";
}

student::~student()
{
	cout << "student destory\n";
}

int main(void)
{
	student s(1,2,3);

	s.showgrade();

	return 0;
}