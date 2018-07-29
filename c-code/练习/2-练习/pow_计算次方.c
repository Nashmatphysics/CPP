/*
2018/07/11
pow_计算次方
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

int main1(void)
{
	int num = 0;
	for (int i = 0; i < 5 ; i++)
	{
	num = (int)pow(10, i);
	printf("%d\n", num);
	}

//getchar();
system("pause");
return 0;
}

int main2(void)
{
	char str[128] = "";
	if (!strcmp(str, ""))
	{
		printf("yes\n");
	}
	else
		printf("no\n");
	system("pause");
	return 0;
}
int main(void)
{
	char str[128] = "";
	fgets(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}