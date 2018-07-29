/*
2018/07/03
显示类型极限大小
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
# include <limits.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

int main(void)
{
	printf("%d\n%d\n", INT_MAX, INT_MIN);
	//这里的INT_MAX, INT_MIN为#define定义的宏, 为一个整型常量, 其声明在limits.h中
	printf("%d\n", CHAR_MAX);
	printf("%d\n", CHAR_MIN);
	system("pause");
	return 0;
}