/*
2018/06/23
二维数组
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

/***********************************对二维数组排序*************************************/
void rand_fun(int *a, int count);
void sort_fun(int *a, int count);

int main(void)
{
	int a[7][8] = {0};
	int count = sizeof(a) / sizeof(int);
	rand_fun((int *)a, count);
	sort_fun((int *)a, count);
	//二维数组的遍历
	for (int i= 0; i< 7; ++i)
	{
		for (int k = 0; k < 8; ++k)
		{
			printf("%d\n", a[i][k]);
		}
	}

//getchar();
system("pause");
return 0;
}

void rand_fun(int *a, int count)
{
	srand((int)time(NULL));

	for (int i = 0; i < count; ++i)
	{
		a[i] = rand() % 100;
	}
}

//排序
//思路: 将二维数组转成一维数组进行排序.
void sort_fun(int *a, int count)
{
	/*判断输入是否合法*/

	for (int i = 1; i < count; ++i)
	{
		for (int j = 0; j < (count - i); ++j)
		{
			int temp = 0;
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
/*
思想: 多维数组的赋值和排序都可通过转换为一维数组来操作.
*/
/***********************************求每一行的最大值*************************************/

/***********************************判断矩阵是否对称*************************************/
/***********************************矩阵的相乘*************************************/