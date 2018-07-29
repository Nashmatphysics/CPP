/*2018/06/07
static的用法.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "static_function.h"

/**************************static修饰变量********************************/

//1.静态变量保存在静态区,函数运行结束变量也不会被销毁.函数下次运行时仍能用到这个值(只要程序没有结束.).
//2.在所有函数之外定义的静态变量称为全局静态变量, 函数内定义的static变量是局部静态变量, 包括main()

/**静态全局变量*/
/*
1.作用域仅限于变量定义的文件中.其他文件使用extern也没用
2.在定义之前的地方也无法使用它.
*/
static int number = 23;

/*静态局部变量*/
//只在该函数体中有用.在本文件中的其他函数均用不了.
void app()
{
	static int i = 0;
	printf("i: %d\n", i);
	printf("number: %d\n", number);
	++i;
}

int main2(void)
{
	for (int i = 0; i < 2; ++i)
	{
		app();
	}
	printf("number: %d\n", number);

	getchar();
	return 0;
}

/**************************static修饰函数********************************/
/*静态函数/内部函数*/
/*
1.作用域只在本文件内部, 其他文件无法使用,即使包含其头文件.
2.好处: 不用担心与其他文件的函数同名.
*/

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("please enter!\n");
	}
	no_static(argv[1]);
	//print(argv[1]);//error

	getchar();
	return 0;
}

/*
补充:
1.声明和定义的区别
声明: 2种情况: a.这个变量或函数在其他地方定义了, 自己找去! b.这个变量/函数名我先预定了,即打桩,比如头文件中的函数接口声明, 编译没有问题.
定义: 分配内存空间, 加个名字.名字和这块内存绑死, 不能改变. 
*/