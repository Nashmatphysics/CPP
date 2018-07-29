#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>
#include "myguess.h"

void itoia(int *array, int num)
{
	for (int i = NUM_LINE - 1; i >= 0; --i)
	{
		//printf("%d\n", num);
		int ntoc = (int)(num / ((int)pow(10, i)));
		array[i] = ntoc;
		num = num % ((int)pow(10, i));
		//printf("%d\n", array[i]);
	}

	//倒置数字
	int head_num = 0;
	int last_num = NUM_LINE - 1;
	while (last_num > head_num)
	{
		int temp_num = array[head_num];
		array[head_num] = array[last_num];
		array[last_num] = temp_num;
		head_num++;
		last_num--;
	}
}

void to_dif(int *sourc)
{
	int temp = *sourc;
	//printf("%d\n", *sourc);
	//int temp = 1030;
	if (sourc == NULL)
	{
		printf("to_dif: input error\n");
		return;
	}

	//把数字转成数组.
	//printf("%d\n", temp);
	int array[NUM_LINE] = { 0 };

	itoia(array, temp);

	//转成不同的数字.
	for (int i = 0; i < NUM_LINE; ++i)
	{
		for (int j = 0; j < NUM_LINE; ++j)
		{
			if ((array[j] == array[i]) && (i != j))
			{
				srand((int)time(0));
				array[i] = rand() % 10;
				i = 0;
			}
		}
	}
	/*
	   for (int i = 0; i < NUM_LINE; ++i)
	   {
	   printf("%d\n", array[i]);
	   }
	   printf("========================\n");
	   */
	   //数组转成数字--->temp.
	char temp_str[STR_LINE] = "";
	for (int i = 0; i < NUM_LINE; ++i)
	{
		sprintf(temp_str + i, "%d", array[i]);//sprintf每次都会从字符串首地址开始写, 所以会覆盖.
	}
	//printf("%s\n", temp_str);
	*sourc = atoi(temp_str);
	//printf("%d\n", *sourc);
}

int rand_num(void)
{
	int temp = 0;
	//产生一个四位数字
	srand((int)time(NULL));
	temp = (int)rand() % RAND_NUM;
	if ((int)(temp / 1000) == 0)
	{
		temp = temp + 1000;
	}
	//printf("%d\n", temp);
	//设置四位数字互不相同.
	to_dif(&temp);
	return temp;
}

int judge_fun(char *str, int size)
{
	if (!strcmp(str, GIVE_STR))
		return 1;

	for (int i = 0; i < size; ++i)
	{
		if (!isdigit(str[i]))
			return 3;
	}
	if (size != 4)
		return 3;
	return 2;
	/* 1: I GIVE UP
	 * 2: number
	 * 3: wrong input
	 */
}

//字符转成数字.
int trans_num(char *str, int size)
{
	int temp = 0;
	temp = atoi(str);
	return temp;
}

//全部猜对返回1
int compare_fun(int in_num, int source_num, char *out_str/*out*/)
{
	/* out_str:
	 * A:数字和位置都正确
	 * B:数字正确, 位置错误
	 * 0000: 没有一个数字正确
	 *
	 * I GIVE UP && 正确答案:
	 * source_num
	 */
	char array[STR_LINE] = "";
	int in_array[NUM_LINE] = { 0 };
	int sourc_array[NUM_LINE] = { 0 };
	//数字转成数组.
	itoia(in_array, in_num);
	itoia(sourc_array, source_num);
	int count = 0;

	for (int i = 0; i < NUM_LINE; ++i)
	{
		for (int j = 0; j < NUM_LINE; ++j)
		{
			if (in_array[i] == sourc_array[j])
			{
				if (i == j)
					array[count] = 'A';
				else
					array[count] = 'B';
				count++;
			}
		}
	}

	if (!strcmp(array, "AAAA"))
	{
		sprintf(out_str, "%d", source_num);
		return 1;
	}

	if (!strcmp(array, ""))
	{
		sprintf(out_str, "0000");
	}
	else
	{
		sprintf(out_str, "%s", array);
	}
	return 0;

}
