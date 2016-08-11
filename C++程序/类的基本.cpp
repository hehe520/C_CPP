#include <iostream>
using namespace std;

class stu
{
private:
	int age;
	int num;
public:
	void showmsg()
	{
		cout << "age = " << age << endl;
		cout << "num = " << num << endl;
	}
	int ave(float a, float b)
	{
		age = a;
		num = b;
		return (a+b)/2;
	}
	void clear(int x);
};

void stu::clear(int a)
{
	system("cls");
	cout << a << endl;
}

int main(void)
{
	int a, b;
	stu s;
	cin >> a >> b;
	cout << "ave = " << s.ave(a, b) << endl;
	s.showmsg();
	getchar();
	s.clear(10);
	
	return 0;
}