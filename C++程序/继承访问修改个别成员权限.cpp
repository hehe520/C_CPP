#include <iostream>
#include <string>
using namespace std;

// 就是私有或保护继承的个别成员，在子类中改为公有或其他的

class person
{
public:
	person::person(string n="0", string s="0", string id="0");
	string name;
	string sex;
protected:
	void showp();
private:
	string IDnum;
	void showID();
};

class stu: private person
{
public:
	stu::stu(int g=0, int s=0, 
		string n="NUL", string sex="NUL", string id="NUL");
	int grade;
	int schoolnum;
	void show();
	person::name;   // 私有继承后，个别调整为公有
	person::showp;  // 保护的经过私有继承改为公有的
};

// --------person-----------
person::person(string n, string s, string id)
{
	name = n;
	sex = s;
	IDnum = id;
}

void person::showp()
{
	cout << "姓名：" << name << endl;
	cout << "性别：" << sex << endl;
	cout << "ID：" << IDnum << endl;
}

void person::showID()
{
	cout << "身份证号:" << IDnum << endl;
}

// --------stu----------
stu::stu(int g, int s, string n, string sex, string id)
:person(n, sex, id)
{
	grade = g;
	schoolnum = s;
}

void stu::show()
{
	person::showp();
	cout << "成绩：" << grade << endl;
	cout << "学号：" << schoolnum << endl;
}

int main(void)
{
	stu s(98, 110202, "wujiaying", "女", "7058");

	s.show();
	cout << endl;
	s.name = "ck";
	s.show();
	cout << endl;
	s.showp();

	return 0;
}

