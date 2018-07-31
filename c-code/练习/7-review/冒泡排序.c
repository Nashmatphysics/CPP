/*
2018/07/31

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

int creat_array(int *array[], int count);
void des_array(int *array[]);
void sort_array(int *array, int count);
void travel_fun(int *array, int count, void(*func)(int vary));
void act_fun(int vary);
void rand_fun(int *array, int count);

int main(void)
{
	int *array = NULL;
	int count = 0;
	printf("please enter the count:\n");
	scanf("%d", &count);
	int ret = 0;
	ret = creat_array(&array, count);
	if (ret != 0)
	{
		printf("creat failed\n");
		return -1;
	}

	travel_fun(array, count, act_fun);

	sort_array(array, count);

	travel_fun(array, count, act_fun);
	des_array(&array);

	//getchar();
	system("pause");
	return 0;
}

int creat_array(int *array[], int count)
{
	int ret = 0;
	if ((array == NULL) || (count <= 0))
	{
		ret = -1;
		goto END;
	}
	int *t_array = NULL;
	t_array = (int *)malloc(count * sizeof(int));
	if (t_array == NULL)
	{
		ret = -2;
		printf("malloc error\n");
		goto END;
	}

	rand_fun(t_array, count);
	*array = t_array;

END:
	return 0;
}

void des_array(int *array[])
{
	if (array == NULL)
		return;
	if (*array != NULL)
	{
		free(*array);
		*array = NULL;
	}
}

void sort_array(int *array, int count)
{
	if ((array == NULL) || (count <= 0))
	{
		printf("sort_array input error\n");
		return;
	}
	int *t_array = array;
	int index = 0;
	for (int j = count; j > 0; j--)
	{
		for (int i = 0; i < j; i++)
		{
			if (t_array[index] < t_array[i])
			{
				index = i;
			}
		}
		int temp = t_array[index];
		t_array[index] = t_array[j - 1];
		t_array[j - 1] = temp;
	}
}

void travel_fun(int *array, int count, void (*func)(int vary))
{
	if ((array == NULL) || (count <= 0) || (func == NULL))
	{
		printf("travel_fun input error\n");
		return;
	}
	int *temp = array;
	for (int i = 0; i < count; i++)
	{
		func(temp[i]);
	}
	putchar('\n');
	printf("==================================\n");
}

void act_fun(int vary)
{
	printf("%d\t", vary);
}

void rand_fun(int *array, int count)
{
	if ((array == NULL) || (count <= 0))
	{
		printf("rand_fun input error\n");
		return;
	}
	int *temp = array;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < count; i++)
	{
		temp[i] = rand() % 100;
	}
}