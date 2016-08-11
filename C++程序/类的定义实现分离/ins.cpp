#include "point.h"
// 自定义的头文件要用 " "

void point::input(int a, int b)
{
//	show();
	x = a;
	y = b;
}

int point::getx(void) 
{
	return x;
}

int point::gety(void)
{
	return y;
}

