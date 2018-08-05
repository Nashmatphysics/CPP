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

int creat_array(int **array, int count);
void des_array(int *array[]);
void sort_array(int *array, int count);
void travel_fun(int *array, int count, void(*func)(int vary));
void tra_func(int *array, int count);
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
	printf("=================\n");
	sort_array(array, count);
	tra_func(array, count);
	des_array(&array);

	//getchar();
	system("pause");
	return 0;
}

//创建动态数组.
int creat_array(int **array, int count)
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
	memset(t_array, 0, count * sizeof(int));
	rand_fun(t_array, count);
	*array = t_array;

END:
	return 0;
}

//销毁数组
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

//排序
void sort_array(int *array, int count)
{
	if ((array == NULL))
	{
		printf("sort_array input error\n");
		return;
	}
	
	if (!(count > 0))//条件判断
	{
		return;
	}
	/*
	//冒泡排序-----> ok
	for (int i = 1; i < count; i++)
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
	*/
	/*
	//选择排序
	//int *t_array = array;
	//int index = 0;//index不能放到循环外面, 否则每次循环的初始值不为0!
	for (int j = count; j > 0; --j)//实际只需要循环count-1次, 但是这里循环了count次
	{
		int index = 0;
		for (int i = 0; i < j; i++)//循环了j次. i最后为j
		{
			if (array[index] < array[i])
			{
				index = i;
			}
		}
		int temp = array[index];
		array[index] = array[j - 1];
		array[j - 1] = temp;
	}
	*/
	//递归方式的选择排序
	int index = 0;
	for (int i = 0; i < count; i++)//执行体
	{
		if (array[index] < array[i])
		{
			index = i;
		}
	}
	int temp = array[index];
	array[index] = array[count-1];
	array[count - 1] = temp;
	sort_array(array, --count);//app
}

//遍历数组1-->回调函数.
void travel_fun(int *array, int count, void(*func)(int vary))
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

//遍历数组2
void tra_func(int *array, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d\t", array[i]);
	}
}

//回调动作函数
void act_fun(int vary)
{
	printf("%d\t", vary);
}

//随机数生成函数.
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