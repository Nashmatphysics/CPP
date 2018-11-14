/*
2018/11/05
编码和进制
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

int main(void)
{
	//printf("%d\n", sizeof(void *));
	//int a = 08;//error,前面添0表示8进制.
	if(0)
	{
		//8进制
	int a = 017;//15;
	printf("%d\n", a);
	}
	if(1)
	{
		//16进制
		int a = 0Xa1;//10*16 + 1 = 161;
		printf("%d\n", a);
	}


//getchar();
system("pause");
return 0;
}