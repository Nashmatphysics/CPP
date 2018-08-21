/*
2018/07/07
C语言中的__FILE__, __LINE__, __func__
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

int main1(void)
{
	printf("%s\n", __FILE__);//指示本行语句所在源文件的文件名
	printf("%d\n", __LINE__);//指示本行语句在源文件中的位置信息
	printf("%s\n", __func__);//指示所在的函数名
	printf("%s\n", __FUNCTION__);//同__func__作用相同
	//getchar();
	system("pause");
	return 0;
}

//还可以通过语句#line来重新设定__LINE__的值，举例如下：
#line 200 //指定下一行的位置信息)为200
int main2(void)//200
{
	printf("%d\n", __LINE__);//202
	system("pause");
	return 0;
};