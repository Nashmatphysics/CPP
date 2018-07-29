/*
2018/07/03
浮点数无法精确存储的问题
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

int main(void)
{
	float i = 99.9;
	printf("%f\n", i);
	//99.900002
	/*因为浮点数无法准确存储,所以就衍生出2个问题:
	1.有一个浮点型变量x, 如何判断x的值是否为0
	if(|x-0.000001| <= 0.000001)
		是0
	else
		不是0
	2.为什么循环中更新的变量不能定义成浮点型.
	*/
	float x = 0.00001;
	if ((fabs(x) - 0.000001) <= 0.000001)
		printf("is 0\n");
	else
		printf("is not 0\n");

//getchar();
system("pause");
return 0;
}