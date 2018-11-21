/*
2018/11/20

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

/***********************************calloc()*************************************/
int main1(void)
{
	int * p = NULL;
	p = (int *)calloc(5, sizeof(int));

	for (int i = 0; i < 5; ++i)
	{
		printf("%d\t", p[i]);
	}
	free(p);
	printf("%d\t", p[1]);
	int *q = NULL;
	

//getchar();
system("pause");
return 0;
}

int main(void)
{
	int a[10] = {1};
	printf("%d\n", a[0]);
	printf("%d\n", *a);
	printf("%#x\n", a);
	printf("%#x\n", &a[0]);
	system("pause");
	return 0;
}