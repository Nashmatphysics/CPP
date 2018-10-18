/*
   2018/06/22
   */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

/********************unsigned int 和 signed int之间的运算规则****************************/
//当表达式中存在有符号类型和无符号类型时所有的操作数都先自动转换为无符号类型(对于任何运算符都适用)
int main(void)
{
    unsigned int unsigned_var = 20;
    signed int signed_var = -1020;
    (unsigned_var > signed_var) ? puts("left"):puts("right");
    unsigned int i = unsigned_var + signed_var;
    printf("%u\n", i);
    /*
       right
       4294966296
    */
    system("pause");
    return 0;
}
