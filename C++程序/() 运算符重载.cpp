#include <iostream>
using namespace std;

class point
{
public:
	point(int a, int b)
	{ x = a;  y = b; }
	int operator ()(int a);		// ()运算符重载
private:
	int x;
	int y;
};

int point::operator ()(int a)
{
	return a + 1;
}

int main()
{
	point inc(1, 2);

	int k = inc(5);		// 假函数，其实是()重载
	k = inc.operator () (5);	

	cout << k << endl;

	return 0;
}