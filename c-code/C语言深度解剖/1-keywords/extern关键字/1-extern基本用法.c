/*
2018/07/01
extern
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include "test_fun.h"

/***********************************extren的作用*************************************/
//extern的作用跟头文件声明一样, 告诉编译器,这个对象是在其他源文件中定义的,可以用extern代替头文件声明, 二者都存在也没有问题
//如果要使用其他文件中的函数和全局变量(特别是不在头文件声明的),除引用头文件外,还需使用extern声明
extern void fun1(void);
extern int a;//头文件中没有声明, 引用头文件也没用, 必须使用extern.

int main(void)
{
	fun1();
	printf("%d\n", a);
//getchar();
system("pause");
return 0;
}