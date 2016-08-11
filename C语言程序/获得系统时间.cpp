#include <stdio.h>
#include <time.h>

int main(void)
{ 
	struct tm *tmp;
	time_t secnow;
	int hour1, min1, sec1;

	time(&secnow);	// 获得时间 
	tmp = localtime(&secnow);

	hour1 = tmp->tm_hour;
	min1 = tmp->tm_min;
	sec1 = tmp->tm_sec;
	printf("[%02d:%02d:%02d]\n",hour1,min1, sec1);

	return 0;
}