#include <iostream.h>
#include <string.h>

// 字符串采用堆储存
class hstring
{
public:
	hstring(char *s = NULL);
	~hstring();
	// 赋值运算符必须为类成员
	hstring &operator = (const hstring &a);
	// 用 cout 输出自己的 hstring
	friend ostream &operator << (ostream &oc, hstring &a);
	int getlen()
	{ return lenth; }
private:
	int lenth;
	char *str;		// 字符串基址
};

hstring::hstring(char *s)
{
	if (s)
	{
		lenth = strlen(s);	// strlen(); 不能对 NULL 求长度
		str = new char [lenth + 1];   // 开辟新空间
		strcpy(str, s);
	}
	else 
	{
		lenth = 0;
		str = NULL;
	}
}

hstring::~hstring()
{
	if (str) delete [] str;
}

// 输出流out
ostream &operator << (ostream &out, hstring &a)
{
	out << a.str;	// 把 cout 传进来
	return out;
}

// 赋值运算符'='重载
hstring &hstring::operator = (const hstring &a)
{
	if (&a == this) return *this;	// 如果是自己
	
	if (str) delete [] str;		// 释放原来的
	lenth = a.lenth;			// 类的内部，lenth 可以访问
	str = new char[lenth + 1];	// 另起炉灶
	strcpy(str, a.str);			// 复制过来

	return *this;
}

int main(void)
{
	hstring s1 = "123456";
	hstring s2("wujiaying");

	cout << s2 << endl;
	cout << s1 << endl;
	operator << (cout, s1);   // 等价于上面语句

	s2 = s1;				// 隐式调用 '='
	cout << endl << s2 << endl;

	s2.operator = (s1);		// 显式调用 '=' 
	cout << s2 << endl;
	cout << "lenth = " << s2.getlen() << endl;

	return 0;
}