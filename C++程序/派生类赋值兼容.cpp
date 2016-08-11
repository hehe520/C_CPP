#include <iostream>

using namespace std;

class base
{
public:
	base::base(int a=0, int b=0)
	{
		x = a;
		y = b;
	}
	void show2()
	{
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}
	int x;
	int y;
};

class child: public base
{
public:
	child::child(int a=0, int b=0, 
		int c=0, int d=0): base(a, b)
	{
		z = c;
		w = d;
	}
	void show()
	{
		show2();
	//	base::show2();
		cout << "z = " << z << endl;
		cout << "w = " << w << endl;
	}
	int z;
	int w;
};

int main(void)
{
	child c(1,2,3,4);
	c.show();

	cout << endl;
	base b;
	b = c;		// c 必须是 b 的公有派生
	b.show2();

	cout << endl;
	base *b1;
	b1 = &c;
	b1->show2();

	cout << endl;
	base &b2 = c;
	b2.show2();

	return 0;
}
