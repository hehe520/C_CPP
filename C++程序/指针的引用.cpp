#include <iostream>

using namespace std;

// char * &p 指针的引用, 这里修改p，等于修改main中的p
// 而不是简单的把 p 的值复制过来
// char &p = i;
void test(char * &p)
{
	p = new char('H');
}

int main(void)
{
	char *p;

	p = new char('k');
	cout << *p << endl;

	test(p);
	cout << *p << endl;

	delete p;

	return 0;
}