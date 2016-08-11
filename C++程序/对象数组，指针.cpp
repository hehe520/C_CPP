#include <iostream.h>
//using namespace std;

class point
{
public:
	point(int a=0, int b=0);
	~point();
	int getx();
	int gety();
	void show();
	void input(int, int);
	void viewaddr();
private:
	int x;
	int y;
};


point::~point()
{
	cout << this << " 已销毁" << endl;
}

point::point(int a, int b): x(a), y(b)
{
//	x = a;
//	y = b;
}

void point::show()
{
	cout << '(' << x << ',' << y << ')' << endl;
}

void point::input(int a, int b)
{
	x = a;
	y = b;
}

void point::viewaddr()
{
	cout << this->x << endl;
}

int point::getx() { return x; }
int point::gety() { return y; }

int main()
{
	point s[10] = {	point(1,1),
					point(2,2), 
					point(3,3),
					point(4,4),
					point(5,5)};

	s[0].input(10, 20);
	s[1] = s[0];
	s[0].show();
	s[1].show();
	s[2].show();
	
	cout << "函数地址:";
	s[0].viewaddr();

	point *q = &(s[3]);
	q->show();
	q++;
	q->show();

	point *p = new point(111,222);
	p->show();

	delete p;
	return 0;
}
