#include <iostream>

using namespace std;

int main()
{
	cout << "wu" << endl;
	cerr << "caokun" << endl;	// 不经缓冲区
	clog << "jiaying" << endl;	// 经缓冲区

	cout.put('a');		// 等价于 cout << 'a';
	cout.put('\n');
	
	char a;
	cin.get(a);
	cout << a << endl;

	char buf[100];
	cin >> buf;		// 不读入空格等等...
	cout << buf << endl;

	char buf2[20];
	cin.get(buf2, 5, 'q');	// 读入空格,等等
	cout << buf2 << endl;	

	cin.ignore(5, 'q');		// 忽略 5 个字符

	return 0;
}