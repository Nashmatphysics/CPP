/*
2018/11/22
数组指针做形参的真正含义
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

void func1(int b[10], int(*q)[10])
{
	printf("%d\n", sizeof(*q));//q是数组指针, 但保存的是&数组, 所以*q即为数组名, 是一个指针常量.
	printf("%d\n", sizeof(q));
	printf("%d\n", sizeof(b));//形参虽然写的是数组, 但b其实是普通的指针变量
}

void func2(int b[10], int *q[])
{
	printf("%d\n", sizeof(*q));//q是数组指针, 但保存的是&数组, 所以*q即为数组名, 是一个指针常量.
	printf("%d\n", sizeof(q));
	printf("%d\n", sizeof(b));//形参虽然写的是数组, 但b其实是普通的指针变量
}
int main(void)
{
	int(*p)[10] = NULL;
	int a[10] = {0};
	for (int i = 0; i < 10; i++)
	{
		a[i] = i+1;
	}
	/*
	//eg 1: int (*q)[10]中: *q的结果
	p = &a;
	printf("%d\n", sizeof(a));
	printf("%d\n", sizeof(*p));
	printf("-------------------\n");
	func1(a, p);
	*/

	//eg 2: 函数形参是int (*q)[10]
	int * c = (int *)calloc(20, sizeof(int));
	p = (int (*)[10])&c;//神奇的事情
	func1(c, p);
	//表明int *q[10]是正儿八经的数组指针,不会转换为二级指针

	//eg 3: 函数形参是int *q[] / int **q.
	int **j = &c;
	func2(c, j);
	//可以发现:int *q[] , int *q[10]完全等价于 int **q.

//getchar();
system("pause");
return 0;
}

/*
总结:
1.在 int (*p)[10] 为非野指针的前提下: 任何 *p 都表示一个真正的数组,即sizeof(*p)都为元素为10的数组的长度.
2.int (*p)[10]做形参时也是数组指针, 并不会转换成二级指针.
*/