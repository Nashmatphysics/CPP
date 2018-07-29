
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "static_function.h"

static void print(char *arg)
{
	printf("%s\n", arg);
}

//其他文件不可调用static函数, 但本文件可以.
void no_static(char *arg)
{
	//printf("%s\n", arg);
	print(arg);

}