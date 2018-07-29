/*
2018/07/08
冒泡排序
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>

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

int main(void)
{
	int array[20] = { 0 };
	int count = 0;
	count = 20;
	rand_fun(array, count);
	sort_fun(array, count);
	print_fun(array, count);

	//getchar();
	system("pause");
	return 0;
}
