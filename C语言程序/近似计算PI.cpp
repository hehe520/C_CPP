#include <stdio.h>

double fabs(double n)
{
	return n >= 0 ? n : -n;
}

int main()
{
	double an, sn;
	int i=0, f;

	f = 1;
	an = 1.0;
	sn = 0.0;
	while(fabs(an) > 1e-6)
	{
		an = f*(double)1/(2*i+1);
		sn += an;
		f = -f;
		i++;
		printf("%.7lf\n", 4*sn);
	}

return 0;
}
