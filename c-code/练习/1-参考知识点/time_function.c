/*
2018/07/04
time相关函数.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>

int main(void)
{
	time_t t;
	time(&t);//获取时间long long 整型
	printf("%lld\n", t);
	struct tm *ltime = NULL;//tm 时间信息结构体
	ltime = localtime(&t); //本地区的时间格式
	printf("%d-%d-%d\n", ltime->tm_year + 1900, ltime->tm_mon + 1, ltime->tm_mday);
	ltime = gmtime(&t); //转换为国际标准格式.
	printf("%d-%d-%d\n", ltime->tm_year + 1900, ltime->tm_mon + 1, ltime->tm_mday);
	printf("%s", ctime(&t));//时间转换为字符串格式的时间
	printf("%s", asctime(ltime));//时间转换为字符串格式的时间
	//getchar();
	system("pause");
	return 0;
}