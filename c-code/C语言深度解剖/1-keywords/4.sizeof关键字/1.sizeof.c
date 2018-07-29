#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/********************1.sizeof不是函数*********************/
int main1(void)
{
	int i = 0;
	printf("int : %d\n", sizeof i);
	//printf("int : %d\n", sizeof int);//error
	//int b = sizeof(int);
	printf("int : %d\n", sizeof int);//error

	getchar();
	return 0;
}

/*****************2. sizeof (int) *p 的含义************************/
int main2(void)
{
	printf("%d\n", sizeof (int));

	int i = 0;
	int p = 6;
	i = sizeof (int) *p;//乘法含义.
	printf("%d\n", i);

	int *q = NULL;
	printf("sizeof(q): %d\n", sizeof(q));
	printf("sizeof(*q): %d\n", sizeof(*q));
	int a[100];
	printf("sizeof(a): %d\n", sizeof(a));
	printf("sizeof(a[100]): %d\n", sizeof(a[100]));
	printf("sizeof(&a): %d\n", sizeof(&a));
	printf("sizeof(&a[0]): %d\n", sizeof(&a[0]));
	

	getchar();
	return 0;
}
/*****************sizeof(b);的值是多少?****************************/
int b[100];

void fun(int b[100])
{
	sizeof(b);//sizeof(b);的值是多少?
	printf("%d", sizeof(b));
}

int main3(void)
{
	int a[100] = {0};
	fun(a);
	getchar();
	return 0;
}
/************
4
*************/
/*
原因:
1.全局数组(注意:全局变量不是静态变量)b[100]是数组.而fun形参int b[100],不是数组, 而是退化为 int *b--->不是常量指针;
2.原始数组名是只读指针, 而int *bzhishi
*/