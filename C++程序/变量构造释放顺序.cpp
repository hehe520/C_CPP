#include <iostream>
using namespace std;

class test
{
public:
	test(int i)
	{ id = i;  cout << "num " << id << " created" << endl; }
	~test()
	{ cout << "~num " << id << " destoryed" << endl; }
private:
	int id;
};

int main()
{
	test t1(1);
	test t2(2);
	test t3(3), t4(4), t5(5);

	// 变量构造，释放顺序，

	return 0;
}