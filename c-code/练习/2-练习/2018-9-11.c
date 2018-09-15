/*
2018 / 9 / 11
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

void my_recursion(int * sum, int begin, int end)
{
	int init = end;
	if (init <= begin)
	{
		*sum = 1;
		return;
	}

	my_recursion(sum, begin, init - 1);
	*sum = (*sum) + init;
}

int my_recursion2(int begin, int end)
{
	int init = end;
	int sum = 0;
	if (init <= begin)
	{
		return 1;
	}
	sum = my_recursion2(begin, init - 1);
	sum = sum + init;
	return sum;

}

int main(void)
{
	int begin = 1;
	int end = 100;
	int sum = 0;
	//my_recursion(&sum, begin, end);
	sum = my_recursion2(begin, end);
	printf("%d\n", sum);

	//getchar();
	system("pause");
	return 0;
}