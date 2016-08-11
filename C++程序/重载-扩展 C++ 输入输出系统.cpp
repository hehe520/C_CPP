#include <iostream>
using namespace std;

// 重载 >> << 扩展 C++ 输入输出系统

class point
{
public:
	point();
	// 友元重载, 返回 istream 的引用
	friend istream &operator >> (istream &in, point &p);
	friend ostream &operator << (ostream &out, point &p);
private:
	int x;
	int y;
};

point::point()
{ x = 0;   y = 0; }

istream &operator >> (istream &in, point &p)
{
	in >> p.x >> p.y;
	return in;
}

ostream &operator << (ostream &out, point &p)
{
	out << "(";
	out << p.x << "," << p.y;
	out << ")";
	return out;
}

int main()
{
	point p;

	cin >> p;
	cout << p << endl;

	return 0;
}
