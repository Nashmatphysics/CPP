/*
2018/07/03

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

int main(void)
{

	char a[5] = "hello";
	//有3种情况:
	//1.输出hello后面接乱码, 因为printf靠识别\0结束输出
	//2.输出hello后程序崩溃, 因为在寻找\0的过程中访问到了系统保护的内存
	//3.正常输出hello, 恰好碰到\0;
	printf("%s\n", a);
//getchar();
system("pause");
return 0;
}