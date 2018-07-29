/*
2018-06-26

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

/**********************************数组名&数组指针**************************************/
int main1(void)
{
    int a[10] = {0};
	printf("%d\n", sizeof(a));
    printf("a: %p, a+1: %p\n", a, a+1);//数组名
    printf("&a: %p, &a + 1: %p\n", &a, (&a) + 1);//数组指针
	printf("a[9]: %p\n", a+9);
    system("pause");
    return 0;
}

