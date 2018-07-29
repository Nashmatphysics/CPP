/*2018/06/07
short的长度是取决于编译器还是系统
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int app(GUI) = 4;

int main(void)
{
	printf("short: %d\n", sizeof(short));
	printf("int: %d\n", sizeof(int));
	printf("char: %d\n", sizeof(char));
	printf("double: %d\n", sizeof(double));
	printf("float: %d\n", sizeof(float));
	printf("long long: %d\n", sizeof(long long));
	printf("long: %d\n", sizeof(long));
	/********************************************************
	=======================WIN7-X64========================
	-------------MSVC-2015-X86------------------
	short: 2
	int: 4
	char: 1
	double: 8
	float: 4
	long long: 8
	long: 4
	---------------GCC-5.1-X64-----------------
	short: 2
	int: 4
	char: 1
	double: 8
	float: 4
	long long: 8
	long: 4
	=======================UBUNTU-16-X64========================
	--------------GCC-5.4-X64------------------
	short: 2
	int: 4
	char: 1
	double: 8
	float: 4
	long long: 8
	long: 8
	**********************************************************/
	getchar();
	return 0;
}
/*
总结:
数据类型长度与系统有关, 与编译器(包括编译器位数)无关.
*/
