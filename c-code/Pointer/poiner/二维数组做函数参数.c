/*
2018/11/22
二维数组做函数参数
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

void func(int a[5][10])//等价于 int a[][10], int (*a)[10]
{
	printf("%d\n", sizeof(a));
}

int main(void)
{
	int a[5][10] = {0};
	printf("%d\n", sizeof(a));
	printf("-------------------\n");
	int array[10] = { 0 };
	int(*b)[10] = &array;
	func(b);
//getchar();
system("pause");
return 0;
}
/*
总结:
二维数组做函数参数,实际变成数组指针,即sizeof()的结果是指针的长度,而没有创建一个二维数组, 这与一维数组做形参保持了一致的变化.
二维数组不是形参时, sizeof()的结果是整个二维数组的长度, 二维数组名可以看做是一个数组指针常量,这也与一维数组保持了一致.
*/