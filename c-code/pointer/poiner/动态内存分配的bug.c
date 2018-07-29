/*
2018/07/03
动态内存分配的bug
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

int main(void)
{
	int * p;
	int i;
	
	p = ( int * )malloc(sizeof(int) * 5);
	memset(p, 0, sizeof(int) * 5);

	printf("请输入i的值\n");
	scanf("%d", &i);
	/*
	if(i>5)
	{
	printf("error out of size\n");
	return -1;
	}
	*/

	for(int j = 0; j < i; ++j)
	{
		printf("%d\n",p[j]);
	}
	system("pause");
	return 0;
}
/*
问题：为什么访问超出动态数组的空间后,程序不会报错？
如何避免? 加个判断.
*/