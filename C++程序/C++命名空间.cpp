#include <iostream>

// 名字空间也可以嵌套, 类似文件目录树
// all::caokun::grade
// 如果用了，using namespace all; 就不用写 all::
namespace all
{
	namespace caokun
	{
		int grade = 100;
	}
	namespace wu
	{
		int grade = 10;
	}
}

namespace test
{
	class point 
	{
	public:
		int x;
		int y;
	};
}
using namespace test;

// 去掉注释，就可以用加 all:: 了
// using namespace all;

int main()
{
	// std 是标准的名字空间
	std::cout << "wujiaying" << std::endl;
	std::cout << all::caokun::grade << std::endl;
	std::cout << all::wu::grade << std::endl;

	point p;
	p.x = 4;
	p.y = 7;

	return 0;
}
