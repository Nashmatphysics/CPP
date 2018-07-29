/*
2018/07/09
二维数组形式的字符串数组内存分布
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

int main(void)
{
	int i;
	char name[][10] = {"xiaoming", "itcast", "xiaoqiang", "xiaohong"};
	char key[10];
	/*
	char a[10] = "xiaoming";	//name[0]  == > a
	char b[10] = "itcast";
	char c[10] = "xiaoqiang";
	char d[10] = "xiaohong";
	*/
	//char name[][10] = {"xiaoming\0\0itcast\0\0\0\0xiaoqiang\0xiaohong\0\0"};

	for (i = 0; i < 4; i++) 
	{
		if (strcmp(name[i], "xiaohong") == 0) {
			printf("%d\t%s\n", i, name[i]);
			strcpy(key, name[i]);
		}
	}
	printf("%s\n", key);
	
	return 0;
}


