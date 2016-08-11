#include <iostream>
using namespace std;

class point
{
public:
	point(int a=0, int b=0)
	{ x = a;   y = b; }
	point operator + (point &a);	// 类外定义
	point operator - (point &a)
	{
		// 高效做法
		return point(x - a.x, y - a.y);
	}
	// 在类中已定义了++，如果再用友元重载++，将引起二义性
	point operator - ();		// 单目运算符
	point operator ++ ();		// 前缀调用
	point operator ++ (int);	// 后缀调用，与前缀又是重载
	void show()
	{ cout << "(" << x << "," << y << ")" << endl; }
private:
	int x;
	int y;
};

point point::operator + (point &a)
{
	point tmp;
	tmp.x = x + a.x;
	tmp.y = y + a.y;
	return tmp;
}

// 把自己减掉
point point::operator - ()
{
	x = -x;
	y = -y;
	return *this;
}

point point::operator ++ ()
{
	// 最好是就在自身减掉，不要新开临时变量减
	++x;
	++y;
	return *this;
}

point point::operator ++ (int)	// 后缀调用
{
	x++;
	y++;
	return *this;
}

int main(void)
{
	point p1(2, 2);  cout << "p1 = ";  p1.show();
	point p2(4, 4);  cout << "p2 = ";  p2.show();
	point p3, p4;

	p3 = p1 + p2;	 cout << "p3 = ";  p3.show();
	p3 = p1.operator + (p2);	  // 显式调用
	cout << "p3 = ";  p3.show();
	p3 = -p3;   cout << "p3 = ";  p3.show();
	p3.operator - ();   p3.show();		// 显示调用单目

	p4 = p1 - p2;    cout << "p4 = ";  p4.show();
	p4 = p1.operator - (p2);
	cout << "p4 = ";  p4.show();
	p4 = p2.operator - (p1);
	cout << "p4 = ";  p4.show();

	p4++;                cout << "p4 = ";  p4.show();
	p4.operator ++ ();   cout << "p4 = ";  p4.show();
	++p4;                cout << "p4 = ";  p4.show();
	p4.operator ++ (0);  cout << "p4 = ";  p4.show();

	return 0;
}
