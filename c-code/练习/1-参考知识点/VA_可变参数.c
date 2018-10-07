/*
2018/07/06
VA_可变参数
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <stdarg.h>
/***********************************可变参数应用场景1*************************************/
//只能适用于形参类型相同的情况
void fun(int count, ...)
//可变参数可以工作的前提是: 定义的变量都是连续的线性存储.
//但是显而易见的是,gcc并没有让这些变量连续的线性存储,vs是否为连续存储也是未知的, 所以并不应该直接使用...,
{
	int *temp = &count;
	for (int i = 0; i < count ; i++)
	{
		temp++;//error, 无法判断fun形参初始化存储的方式(是连续存储呢,还是非连续呢),所以temp++的内容时未知的.
		printf("%d\n", *temp);
	}
}

int main1(void)
{
	fun(4, 1, 2, 3, 4);

//getchar();

system("pause");
return 0;
}
/***********************************可变参数应用场景2*************************************/
/*
自定义格式化I/O函数.
系统提供了vprintf系列格式化字符串的函数，用于编程人员封装自己的I/O函数。
int vprintf / vscanf(const char * format, va_list ap); // 从标准输入/输出格式化字符串 
int vfprintf / vfsacanf(FILE * stream, const char * format, va_list ap); // 从文件流 
int vsprintf / vsscanf(char * s, const char * format, va_list ap); // 从字符串
*/
void TestFun(char* pszDest, int DestLen, const char* pszFormat, ...) 
{ 
va_list args; 
va_start(args, pszFormat); //一定要“...”之前的那个参数
_vsnprintf(pszDest, DestLen, pszFormat, args);//通过pszFormat获得...中参数的类型,从而获取...中的所有参数.
va_end(args); 
}
int main2(void)
{
	char a[128] = "";
	TestFun(a, sizeof(a), "%s aaaaa %d", "nash", 78);//相当于自定义格式化字符函数.
	printf("%s\n", a);
	system("pause");
	return 0;
}
/***********************************可变参数应用场景3*************************************/
/*
各个va_xxx的作用:
va_list arg_ptr：定义一个可以指向个数可变的参数列表指针；
va_start(arg_ptr, argN)：使参数列表指针arg_ptr指向函数参数列表中的第一个可选参数，说明：argN是位于第一个可选参数之前的固定参数，（或者说，最后一个固定参数）
va_arg(arg_ptr, type)：返回参数列表中指针arg_ptr所指的参数，返回类型为type，并使指针arg_ptr指向参数列表中下一个参数。
va_copy(dest, src)：dest，src的类型都是va_list，va_copy()用于复制参数列表指针，将dest初始化为src。
va_end(arg_ptr)：清空参数列表，并置参数指针arg_ptr无效。
说明：指针arg_ptr被置无效后，可以通过调用va_start()、va_copy()恢复arg_ptr。每次调用va_start() / va_copy()后，必须得有相应的va_end()与之匹配。参数指针可以在参数列表中随意地来回移动，但必须在va_start() … va_end()之内。
*/
void testfun2(char name[], ...)
{
	printf("%s\n", name);
	va_list ap = NULL;
	va_start(ap, name);//使得ap指向...中的第一个参数.
	int age = 0;
	age = va_arg(ap, int);//获取ap当前指向的参数的值, 并将ap指向下一个参数.int为当前参数的类型.
	printf("age: %d\n", age);
	char sex = 0;
	/*
	sex = *(char *)ap;//ap已经指向int的下一个参数char.
	printf("%c\n", sex);
	*/
	sex = va_arg(ap, char);
	printf("%c\n", sex);
	va_end(ap);
}

int main(void)
{
	char name[128] = "nash";
	int age = 24;
	char sex = 'b';
	testfun2(name, age, sex);
	system("pause");
	return 0;
}

/***********************************可变参数应用场景3*************************************/
//边界条件的判断
void simple_va_fun(int i, ...)
{ 
va_list arg_ptr; //va_list不一定是指针, 所以不要对其进行NULL初始化
int j=0; 

va_start(arg_ptr, i); 
j = i;
while(j != 0)//使用可变参数必须要做边界判断.
{
	printf("%d\t", j);
	j = va_arg(arg_ptr, int);
}
putchar('\n');
va_end(arg_ptr); 
return; 
} 

int main4(void)
{
	simple_va_fun(100, 0);
	simple_va_fun(100, 200, 300,0);
	system("pause");
	return 0;
}
//总结: 使用可变参数必须要有结束标识变量, 就像c风格的字符串的结束标志符.