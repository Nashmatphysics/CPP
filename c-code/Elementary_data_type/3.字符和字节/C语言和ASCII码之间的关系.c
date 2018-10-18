/*
2018/10/10

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>
#include <limits.h>


int main(void)
{
	char ch = '好';//char类型无法存储超过一个字节的其他类型编码的字符
	printf("%c\n", ch);
	char ch1 = 122;
	printf("%c\n", ch1);

//getchar();
system("pause");
return 0;
}