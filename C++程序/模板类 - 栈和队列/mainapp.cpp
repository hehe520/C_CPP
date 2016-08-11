#include <iostream>
#include "mylist.h"   // 类似 C++ 队列和栈的使用方法

using namespace std;

class point 
{
public:
	point(int a=0, int b=0) 
	{x = a;  y = b;}
	int x, y;
};

int main()
{
	char i;
	char ch;
	queue<char> q;		// 队列测试
	
	for (i='a'; i<='z'; i++)  q.push(i);
	cout << "队列大小: " << q.size() << endl;
	while (!q.empty())
	{
		ch = q.front();
		cout << ch;
		q.pop();
	}
	cout << endl;
	
	// 自定义类的测试
	queue<point> q2;
	point tmp, p[3] = {point(1,2), point(3,4), point(5,6)};
	for (i=0; i<3; i++) q2.push(p[i]);
	cout << "队列大小: " << q2.size() << endl;
	while (!q2.empty())
	{
		tmp = q2.front();
		cout << tmp.x << "," << tmp.y << endl;
		q2.pop();
	}
	cout << endl;

	// 栈测试
	stack<char> s;
	for (i='a'; i<='z'; i++)  s.push(i);
	cout << "栈大小: " << s.size() << endl;
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	cout << endl;

	stack<point> s2;	// 自定义类的测试
	for (i=0; i<3; i++) s2.push(p[i]);
	cout << "栈大小: " << s2.size() << endl;
	while (!s2.empty())
	{
		cout << s2.top().x << "," << s2.top().y << endl;
		s2.pop();
	}
	return 0;
}
