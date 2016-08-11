#include "point.h"
#include <iostream>
using namespace std;

// static 将 show() 锁定在本文件中使用,
static void show()
{
	cout << "file1.cpp 的 show" << endl;
}

int main(void)
{
	point *p = NULL;
	point s;
	int a, b;

	show();
	p = &s;
	cin >> a >> b;
	p->input(a, b);
	cout << (*p).getx() << endl;
	cout << p->gety() << endl;

	return 0;
}
