/*
2018/07/03
字符串的初始化
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

int main(void)
{
	//char str[100] = {};//error, 语法错误,
	char buffer[100] ="";//这是一个空的字符串，长度为100，并且初始化了. 
                        //等价于char str[100] = {0};或char str[100] = {'\0'};因为0和'\0'都表示的是空字符.
	char buffer2[] = "";//这个数组/字符串的长度只有1 
//推荐使用char str[100] = {0};
//getchar();
system("pause");
return 0;
}
