/*
2018/07/01
内存对齐
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

typedef struct st
{
	char sex;
	//double score;
	int age;
	char level;
} st;

/*
原则：
1.结构体内成员按自身长度自对齐。
自身长度，如char=1，short=2，int=4，double=8,。所谓自对齐，指的是该成员的起始位置的内存地址必须是它自身长度的整数倍。如int只能以0,4,8这类的地址开始
2.结构体的总大小为结构体的有效对齐值的整数倍(一般为最小整数倍)

结构体的有效对齐值的确定：
1）当未明确指定时，以结构体中最长的成员的长度为其有效值
2）当用#pragma pack(n)指定时，以n和结构体中最长的成员的长度中较小者为其值。
3）当用__attribute__ ((__packed__))指定长度时，强制按照此值为结构体的有效对齐值
具体见复习文档.
*/
int main(void)
{
	printf("%d\n", sizeof(st));

	//getchar();
	system("pause");
	return 0;
}