/*
2018/07/07
2数互换值(不引入第3个变量)
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

int main(void)
{
	int n, m;
	printf("Please enter two numbers:\n");
	scanf("%d %d", &n, &m);//此处scanf中添加逗号后,在输入时一定要原样输入逗号,否则会出错,m将不能接收正确的数据! 
	n = m + n;
	m = n - m;
	n = n - m;
	printf("The number change is: %d, %d\n", n, m);
	return 0;
}
//复习scanf的用法 
//scanf有无空格不影响输入,因为无论有没有空格,输入数据时都要加空格,以区分两个输入的数
//此方法可以互换整数和浮点数 
