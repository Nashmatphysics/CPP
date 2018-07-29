/*
2016-5-29
求一个数是否为合数，以及他的约数和约数个数.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

int main(void)
{
	int num;
	int count = 0;
	printf("please enter a integer:\n");
	scanf("%d", &num);

	printf("well,let me compute it\n");
	//求一个数约数的个数，只需计算出qurt（num） 内的约数个数即为num约数的个数
	//且此处使用div*div相比于使用sqrt()函数要好，因为sqrt()的形参必须为浮点数。 
	for (int div = 2; (div * div) <= num; ++div)
	{
		if ((num % div) == 0)
		{
			++count;
			if (count == 1)//在循环开始之前说明num为合数 
			{
				printf("OK! I know, %d is an composite number!\n", num);
			}

			if ((num / div) == div)
				//当num为完全平方数时，只需输出div本身 
				printf("%d can be divisible by %d\n", num, div);
			else
				//需要输出div以及num/div才能完整的列出num的约数 
				printf("%d can be divisible by %d and %d\n ", num, div, (num / div));
		}
	}

	if (count == 0)//判断num是否为质数，也可以放在循环结构的前面 
		printf("Sorry! %d is a prime number\n", num);
	system("pause");
	return 0;
}
