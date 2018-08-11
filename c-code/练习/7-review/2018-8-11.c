/*
2018/08/11

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

int creat_func(int **array, int count);
void travel_func(int *array, int count);
void sort_func(int *array, int count);
void des_func(int **array);

int main(void)
{
	int *array = NULL;
	int ret = 0;
	int count = 0;
	printf("please enter number:\n");
	scanf("%d", &count);
	ret = creat_func(&array, count);
	if (ret != 0)
	{
		printf("creat_func error\n");
		return -1;
	}
	travel_func(array, count);
	sort_func(array, count);
	printf("====================================\n");
	travel_func(array, count);
	printf("====================================\n");
	des_func(&array);

	//getchar();
	system("pause");
	return 0;
}

int creat_func(int **array, int count)
{
	int ret = 0;
	if ((array == NULL) || (count <= 0))
	{
		ret = -1;
		printf("creat_fun input error\n");
		goto END;
	}
	int *temp = NULL;
	temp = (int *)malloc(count * sizeof(int));
	if (temp == NULL)
	{
		printf("creat_func::malloc failed\n");
		ret = -2;
		goto END;
	}
	memset(temp, 0, count * sizeof(int));
	srand((unsigned int)time(NULL));

	for (int i = 0; i < count; i++)
	{
		temp[i] = rand() % 100;
		//printf("%d\t", temp[i]);
	}
	//putchar('\n');
	*array = temp;
END:
	return ret;
}

void travel_func(int *array, int count)
{
	if ((array == NULL) || (count <= 0))
	{
		printf("travel_func input error\n");
		return;
	}

	for (int i = 0; i < count; i++)
	{
		printf("%d\t", array[i]);
	}
}

//冒泡排序
/*
void sort_func(int *array, int count)
{
	if ((array == null) || (count <= 0))
	{
		printf("sort_func input error\n");
		return;
	}

	for (int i = 1; i < count; i++)//count-1
	{
		for (int j = 0; j < count-i; j++)
		{
			if (array[j] < array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}

	}
}
*/

//递归方式的冒泡排序.
void sort_func(int *array, int count)
{
	if ((array == NULL))
	{
		printf("sort_func input error\n");
		return;
	}

	if (!(count > 1))
	{
		return;
	}

	//for (int i = 1; i < count; i++)//count-1
	//{
	for (int j = 0; j < count - 1; j++)
	{
		if (array[j] < array[j + 1])
		{
			int temp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = temp;
		}
	}
	--count;
	sort_func(array, count);


	//}

}
void des_func(int **array)
{
	if (array == NULL)
	{
		printf("des_func input error\n");
		return;
	}
	if (*array != NULL)
	{
		free(*array);
		*array = NULL;
	}
}
