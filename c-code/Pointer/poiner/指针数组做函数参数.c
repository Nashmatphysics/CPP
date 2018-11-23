/*
2018/11/22
指针数组做函数参数
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

void func(int *a[10])
{
	printf("ok\n");
}

int main(void)
{
	int *a[10] = {0};
	printf("%d\n", sizeof(a));//40
	int *b = NULL;
	//a = &b;//error
	func(&b);//ok

//getchar();
system("pause");
return 0;
}
/*
总结:
1.指针数组做形参时, 为二级指针变量, 是左值.
2.在非形参的情况下, 指针数组归根结底还是数组, 所以数组名虽然是二级指针, 但是个二级指针常量,不可做左值.
*/