/*
2018/07/03
enum的使用
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

//enum成员只能赋值整型.
enum weekday
{
	Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};//enum中的成员都是#define定义的宏.不可以&

void f(enum weekday i)//这里的形参使用int i,可以吗?--->OK, because enum is int.
//void f(int i)
{
	switch (i)
	{
	case 0: printf("Monday\n"); break;
	case 1: printf("Tuesday\n"); break;
	case 2: printf("Wednesday\n"); break;
	case 3: printf("Thursday\n"); break;
	case 4: printf("Friday\n"); break;
	case 5: printf("Saturday\n"); break;
	case 6: printf("Sunday\n"); break;
	default: printf("error");
	}
}

int main1(void)
{

	enum weekday a;
	printf("请输入星期:\n");
	//scanf("%s", a );//error!--->why?--->enum is int!
	a = Tuesday;
	int i = Wednesday;
	printf("%d\n", i);
	printf("%d\n", sizeof a);
	f(a);

	system("pause");
	return 0;
}
/*
总结:
enum本质就是一个int类型的变量 + #define的结合.
跟#define完全等价, 定义多个常量时, 比用define修改更方便
*/
/***********************************如何使用scanf输入enum?*************************************/
//要实现用户控制输入枚举体, 则只能通过类型转换.
int main2(void)
{

	int i;
	scanf("%d", &i);

	switch ((enum weekday)i)
	{
	case 0: printf("monday\n"); break;
	case 1: printf("tuesday\n"); break;
	case 2: printf("wednesday\n"); break;
	case 3: printf("thursday\n"); break;
	case 4: printf("friday\n"); break;
	case 5: printf("saturday\n"); break;
	case 6: printf("sunday\n"); break;
	default: printf("error\n");
	}
	//printf("%x\t %x\t %x\n", &Monday, &Tuesday, &Wednesday);//error
	system("pause");
	return 0;
}