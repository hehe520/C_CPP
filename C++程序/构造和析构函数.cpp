#include <iostream>
using namespace std;

class date
{
public:
	// 默认参数写在类里
	date(int a=0, int b=0, int c=0);
	date(const date &n);
	~date();
	void showdate();
	void input(int, int, int);
	void input(char *);
//private:
	int y;
	int m;
	int d;
	char *w;
};


class ddd
{
public:
	ddd(const ddd &m);
	ddd(int a=10,int b=10);
	int x;
	int y;
	void show()
	{
		cout << x << "," << y << endl;
	}
};

ddd::ddd(int a, int b)
{
	x = a;
	y = b;
}

ddd::ddd(const ddd &m)
{
	x = m.x;
	y = m.y;
}

// 析构函数释放申请的资源
date::~date()
{
	delete [] w;
}

date::date(const date &n)
{
	y = n.y;
	m = n.m;
	d = n.d;
	w = new char[50];
	strcpy(w, n.w);
}

date::date(int x, int b, int c)
{
	y = x;
	m = b;
	d = c;
	w = new char[50];
	memset(w, 0, sizeof(char));
}

void date::showdate()
{
	printf("%04d,%02d,%02d\n", y, m, d);
	puts(w);
}

void date::input(int a, int b, int c)
{
	y = a;
	m = b;
	d = c;
}

void date::input(char *p)
{
	strcpy(w, p);
}

int main(void)
{
	date d;
	date e(2012, 2, 2);
	date f(e);
	date g = f;
	char s[10] = "sunny";
	ddd k;

	k.x = 6;
	k.y = 1;
	k.show();

	ddd j(k);  // ddd 不写拷贝构造函数也可
	j.show();
	d.input(2010, 10, 5);
	d.input(s);
	d.showdate();

	e.input("rainy");
	e.showdate();
	f.input("wendy");
	f.showdate();
	g.showdate();

	return 0;
}
