/*
2018/07/01
判断当前系统是大端还是小端
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

/***********************************利用union的原理*************************************/
//enum: 所有成员的首地址相同, 且都是从低地址开始.
typedef union product
{
	char type;
	int num;
} product;

int main1(void)
{
	product p1;
	memset(&p1, 0, sizeof(p1));
	p1.num = 1;
	if (p1.type == 1)
		printf("小端存储\n");
	else
		printf("大端存储\n");

	//getchar();
	system("pause");
	return 0;
}
/***********************************利用强制类型转换*************************************/
int main2(void)
{

	int p0 = 0x1122;
	if (*((char*)(&p0)) == 0x11)
	{
		printf("你的计算机为大端存储\n");
	}
	else if (*((char*)(&p0)) == 0x22)
	{
		printf("你的计算机为小端存储\n");
	}
	else
	{
		printf("你的计算机有问题\n");
	}
	system("pause");
	return 0;
}
//小端和大端存储都是以最低位地址作为变量的首地址
//小端和大端都是遵循从低到高位递增的,如a为低位地址, 则a+1为高位地址

/***********************************利用数组下标*************************************/
int main(void)
{
	short int x;
	char x0, x1;
	x = 0x1122;
	x0 = ((char*)&x)[0];//切记:下标本质上是对地址进行操作,对地址运算以后, 再解引用(同样需要单位宽度)
	x1 = ((char*)&x)[1];
	if (x0 == 0x11)
	{
		printf("你的电脑为大端存储法\n");
	}
	else
	{
		printf("你的电脑为小端存储法\n");
	}
	system("pause");
	return 0;
}
//下标运算符是对地址进行运算的,而不仅仅只是数组,对象的地址为: 第一个地址+(下标值*指针类型存放数据类型的长度)
