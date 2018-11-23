/*
2018/11/22
main函数参数
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
//#include <windows.h>
#include <time.h>
#include <stdarg.h>

int main(int argc, char *argv[])//实际上是指针数组, 或者说是二级指针,即char **argv
{
	printf("一共有: %d 个参数\n", argc);
	for (int i = 0; i < argc; i++)
	{
		printf("第 %d 个参数是: %s\n", i+1, argv[i]);
	}

//getchar();
//system("pause");
return 0;
}

/*
./app hello my name is nash
----------------------------
一共有: 6 个参数
第 1 个参数是: ./app
第 2 个参数是: hello
第 3 个参数是: my
第 4 个参数是: name
第 5 个参数是: is
第 6 个参数是: nash
*/
