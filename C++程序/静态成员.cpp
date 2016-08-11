#include <iostream>
#include <string>
using namespace std;

class point
{
public:
	point(int a=0, int b=0);
	~point();
	void show();
	void input(int, int);
	int calc();
	int getx() {return x;}
	int gety() {return y;}
	static int num;
	static void shownum();
private:
	int dis();
	int x;
	int y;
	static int num2;
};

int point::num = 110;
int point::num2 = 220;

point::point(int a, int b)
{
	x = a;
	y = b;
	num = 0;
//	y = calc();
}

point::~point()
{
	cout << this << " destory" << endl;
}

int point::dis()
{
	return x - y;
}

int point::calc()
{
	return x + y;
}

void point::input(int a, int b)
{
	x = a;
	y = b;
}

void point::show()
{
	cout << num << endl;
	cout << "(" << x << "," << y << ")" << endl;
}

void point::shownum()
{
	cout << "num = " << num << endl;
	cout << "num2 = " << num2 << endl;
}

// -----------------------

point *add(point *s)
{
	s->input(s->getx()+1, s->gety()+1);
	return s;
}

int main(void)
{
	point::shownum();	// 静态函数可以不创建对象执行

	point s(1, 3);
	point k;

	add(&s)->show();
	s.num++;
	s.show();
	point::num = 110;	// 也可以
	s.num = 200;
	k.show();
	point::shownum();

	return 0;
}
