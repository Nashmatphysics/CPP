/*
2018/07/04
time相关函数.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>

int main(void)
{
	time_t then;
	//printf("%d\n", (int)then);
	time(&then);//将当前时间存在then中.
	//等价于then = time(NULL);
	printf("%d\n", (int)then);

//getchar();
system("pause");
return 0;
}