/*
2018/07/20
recursion
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>
/***********************************�ݹ�Ӧ�ó���1*************************************/
///////////////�õݹ���׳�///////////////
//1.ʹ��ȫ�ֱ�����ÿ��ݹ��д���ֵ
int sum = 0;
int factorial_fun1(int count)
{
	if (count <= 0)
	{
		return 1;
	}
	sum = factorial_fun1(count-1);
	sum = sum * count;
	return sum;
}

int main1(void)
{
	int count = 10;
	sum = factorial_fun1(count);
	printf("%d\n", sum);

//getchar();
system("pause");
return 0;
}

void factorial_fun2(int count, int *sumptr)
{
	if (count <= 0)
	{
		return;
	}
	factorial_fun2(count - 1, sumptr);
	*sumptr = (*sumptr) * count;
}

int main2(void)
{
	int count = 10;
	int sump = 1;//sump���ܳ�ʼ��Ϊ0; why?
	factorial_fun2(count, &sump);
	printf("%d\n", sump);

//getchar();
system("pause");
return 0;
}

/***********************************�ݹ�Ӧ�ó���2*************************************/
//�ݹ鷽ʽ��ѡ������

void choose_sort(int *array, int count)
{
}

int main(void)
{

//getchar();
system("pause");
return 0;
}
