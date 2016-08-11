#include <stdio.h>

#define MAX 100

// string 是一种新类型，即char [MAX + 1]
// string s;  相当于  char s[MAX + 1]
// 相当于把 string 替换成 s
typedef char string[MAX + 1];

// 同理，函数指针，
// func p;
// 相当于把 func 替换成 p
typedef int (*func)(int a, int b);


int main(void)
{
	int i;
	string s;
	func p;

	return 0;
}