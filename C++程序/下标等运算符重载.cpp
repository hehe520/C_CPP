#include <iostream.h>
#include <string.h>

// 重载 [], +=, >>, << ,=
class hstring
{
public:
	hstring(char *s = NULL);
	~hstring();
	hstring &operator = (hstring &a);
	friend ostream &operator << (ostream &out, hstring &a);
	friend istream &operator >> (istream &in, hstring &a);
	char &operator [] (int x);				// 重载 []
	hstring &operator += (const hstring &a);	// 重载 +=
	int getlen();
private:
	int lenth;
	char *str;
};

hstring::hstring(char *s)
{
	if (s)
	{
		lenth = strlen(s);
		str = new char [lenth + 1];
		strcpy(str, s);
	}
	else 
	{
		str = NULL;
		lenth = 0;
	}
}

hstring::~hstring()
{
	if (str) delete [] str;
	lenth = 0;
}

int hstring::getlen()
{ return lenth; }

hstring &hstring::operator = (hstring &a)
{
	if (&a == this) return *this;
	if (str) delete [] str;
	lenth = strlen(a.str);
	str = new char [lenth + 1];
	strcpy(str, a.str);

	return *this;
}

char &hstring::operator [] (int x)
{
	// 如果 x 不合法，就返回 '\0'
	static char a = '\0';
	if (x < 0 || x > lenth) return a;
	return str[x];
}

// 返回 cin 的别名，可以连续写表达式
istream &operator >> (istream &in, hstring &a)
{
	char buf[1024] = {'\0'};	// 输入缓冲区

	in >> buf;
	a.lenth = strlen(buf);			// 获得新长度
	if (a.str) delete [] a.str;		// 释放原来的
	a.str = new char [a.lenth + 1];	// 另起新空间
	strcpy(a.str, buf);				// 赋值过来

	return in;
}

// 返回 cout 的别名, 作下一个参数
// 可以连续写表达式 cout << s1 << s2;
// operator << (  operator << (cout, s1),  s2); 
ostream &operator << (ostream &out, hstring &a)
{
	if (a.str) out << a.str;
	return out;
}

// 重载 +=
hstring &hstring::operator += (const hstring &a)
{
	if (a.str == NULL) return *this;

	int len = lenth + a.lenth;
	char *tmp = new char [len + 1];	// 建立新空间

	if (str)
	{
		strcpy(tmp, str);		// s1 先进来
		int num = 0;
		char *cur = a.str;
		while (*cur != '\0')
		{
			tmp[lenth + num] = *cur;
			cur++;   num++;
		}
		tmp[lenth + num] = '\0';
		str = tmp;
		lenth = len;
	}
	else 
	{
		strcpy(tmp, a.str);
		str = tmp;
		lenth = len;
	}
	return *this;
}

int main()
{
	hstring s1 = "wujiaying";
	hstring s2 = "520520";

	// 显式调用 << 输出完 s1 后，返回 cout, 给 s2
	operator << (  operator << (cout, s1),  s2); 
	cout << endl;
	cout << s1 << s2 << endl;
	cin >> s1 >> s2;
	cout << s1 << endl;
	cout << s2 << endl;
	// 显式调用 operator << (cout, s2);
	operator << (cout, s1); cout << endl;

	// 访问 s2[0]
	// 显式调用 s2.operator [] (i);
	cout << s1.operator [] (0);
	s1[0] = 'T';
	cout << s1[0] << endl;
	for (int i=0; s2[i]!='\0'; i++) cout << s2[i];
	cout << endl;

	hstring s3, s4;
	s3 += s1;
	s3 += s2;
	s3.operator += (s4);	// 现实调用 +=
	s3 += hstring("caokun");
	cout << s3 << endl;
	return 0;
}