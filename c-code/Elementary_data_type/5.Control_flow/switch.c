/*
switch
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

int main1(void)
{
	char level = 0;
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	while (1)
	{
		level = getchar();
		getchar();
		switch (level) //switch里面只能是char short int long
		{
		case 'A': printf("90-100\n"); ++a; break;
		case 'B': printf("80-90\n"); ++b; break;
		case 'C': printf("70-80\n"); ++c; break;
		case 'D': printf("60-70\n"); ++d; break;
		case 'E': printf("<60\n"); ++e; break;
		case '#': goto loop;
		default: printf("please enter again\n");
		}
	}
loop: printf("A = %d\tB = %d\tC = %d\tD = %d\tE = %d\n", a, b, c, d, e);

	return 0;
}
/*
总结:
对于多判断的情况, 不要想太复杂, 一般用switch就能解决
switch的判断表达式只能为整数(负数也可以)或字符
*/

/***********************************switch嵌套中的break*************************************/
int main(void)
{
	switch (2)
	{
	case 1:
		printf("1111111\n");
		break;
	case 2:
		if (2)
		{
			if (1)
			{
				printf("22222222\n");
				break; //终止的是switch.
			}
		}
	case 3:
		printf("33333333\n");
		break;
	}

	system("pause");
	return 0;
}