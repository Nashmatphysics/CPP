/*
2018/10/10
通过指针判断编译器位数
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
	printf("%d\n", sizeof(void *));

getchar();
return 0;
}
/*
1.为什么可以通过指针判断编译器位数?
指针是存储地址的, 所以必须满足系统的最大寻址要求.
32位系统地址占32位即4个字节.64位系统为64位,即8个字节.
所以只需要判断任意类型指针的大小即可判断编译器位数.
这里的系统应该指的是编译器为程序设定的系统模型.
*/