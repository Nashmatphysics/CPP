/*
2018/07/08
二分法查找
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

void rand_fun(int array[], int count)
{
	srand((int)time(0));
	for (int i = 0; i < count; ++i)
	{
		array[i] = rand() % 100;
	}
}

void print_fun(int array[], int count)
{
	for (int i = 0; i < count; ++i)
	{
		printf("%d\n", array[i]);
	}
}

void sort_fun(int array[], int count)
{
	for (int i = 1; i < count; ++i)
	{
		for (int j = 0; j < count - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
/***********************************循环方式的二分法*************************************/
int seek_fun1(int array[], int count, int num)
{
	int left = 0;
	int right = count - 1;
	int mid = 0;
	//left永远是向右边跑, 而right永远是向左边跑.----->2者不可能有保持永远相等的情况,且left最终将大于right.
	while (1)
	{
		if (left > right)
		{
			return 0;
		}
		mid = (right + left) / 2;
		if (num > array[mid])
		{
			left = mid + 1;
		}
		if (num < array[mid])
		{
			right = mid - 1;
		}
		if (num == array[mid])
		{
			return 1;
		}
	}
	return 0;
}
/***********************************递归方式的二分法*************************************/
int seek_fun(int array[], int count, int num)
{
	int left = 0;
	int right = count - 1;
	int mid = 0;
	//条件判断
	if (left > right)
		return 0;
	//执行体
	mid = (right + left) / 2;
	if (num > array[mid])
	{
		left = mid + 1;
	}
	if (num < array[mid])
	{
		right = mid - 1;
	}
	if (num == array[mid])
	{
		return 1;
	}
	//递归
	return seek_fun(array + left, right - left + 1, num);
}

/***********************************递归方式2*************************************/
int rec_fun(int a[], int l, int r, int number)//用递归进行二分法查找
{
	int mid;
	if (l > r)
	{
		return 0;
	}

	mid = (l + r) / 2;
	if (number > a[mid])
	{
		return rec_fun(a, mid + 1, r, number);
	}
	else if (number < a[mid])
	{
		return rec_fun(a, l, mid - 1, number);
	}
	else
	{
		return 1;
	}
}

int main(void)
{
	int array[20] = { 0 };
	rand_fun(array, 20);
	sort_fun(array, 20);
	print_fun(array, 20);
	printf("enter a number:\n");
	int num = 0;
	scanf("%d", &num);
	int ret = 0;
	//ret = seek_fun(array, 20, num);
	ret = rec_fun(array, 0, 19, num);
	if (ret)
		printf("yes\n");
	else
		printf("no\n");

	//getchar();
	system("pause");
	return 0;
}

/*总结:
 * 1.二分查找法的核心:
 *      通过中间值确定指定值的左右位置, 通过2个变量不断逼近
 * 2.关于递归的二分查找法
 *      递归函数有返回值的, 必须要导出递归的每一层的返回值.
 *      这里的递归模型也是队列式递归.
 */
