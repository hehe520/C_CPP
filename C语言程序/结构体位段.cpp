#include <stdio.h>

typedef struct
{
	unsigned a: 1;  /* 1 Bit, 取值范围: 0 - 1  */
	unsigned b: 2;  /* 2 Bit, 取值范围: 0 - 3  */
	unsigned c: 3;  /* 3 Bit, 取值范围: 0 - 7  */
	unsigned d: 4;  /* 4 Bit, 取值范围: 0 - 15 */
} b;

typedef struct 
{
	int b1 : 1;
	int b2 : 1;
	int b3 : 1;
	int b4 : 1;
	int b5 : 1;
	int b6 : 1;
	int b7 : 1;
	int b8 : 1;
} bit;

int main()
{
	b a;
	a.c = 7;
	printf("%d\n", a.c);

	// 11111111B = 255;
	bit B;
	B.b1 = 1;   B.b2 = 1;   B.b3 = 1;   B.b4 = 1; 
	B.b5 = 1;   B.b6 = 1;   B.b7 = 1;   B.b8 = 1;
	unsigned char *p;
	p = (unsigned char *)&B;
	printf("%d\n", *p);
	
	// 00001111B = 15;
	B.b1 = 1;   B.b2 = 1;   B.b3 = 1;   B.b4 = 1; 
	B.b5 = 0;   B.b6 = 0;   B.b7 = 0;   B.b8 = 0;
	p = (unsigned char *)&B;
	printf("%d\n", *p);

	return 0;
}