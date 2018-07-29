/*
   2018/06/22
   判断一个数是否为素数
   */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

   //1
int main1(void)
{
	//1,2是不是素数?
	int num = 0;
	scanf("%d", &num);
	//if(num)
	for (int i = 1; i < num; ++i)//i != 0
	{
		if ((num % i) == 0)//先写普通情况的处置, 再写特殊情况(i==1)的办法
		{
			if (i == 1)
				continue;
			printf("%d is not prime number\n", num);
			system("pause");
			return 0;
		}
	}

	printf("%d is prime number\n", num);
	//getchar();
	system("pause");
	return 0;
}

//2
int dec_prime(int a)//C中没有bool类型数据.
{
	int j;
	for (j = 2; j < a; ++j)
	{
		if (a%j == 0)
			break;
	}
	if (j == a)
		return 1;
	return 0;
}

int main(void)
{
	int i;
	scanf("%d", &i);
	if (dec_prime(i))
		printf("Yes\n");
	else
		printf("No\n");

	system("pause");
	return 0;
}

//哪种方法好?
//方法2, 编写软件时一定要有函数封装的思想, 这是C语言最重要的思想之一.
