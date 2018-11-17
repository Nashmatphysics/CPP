/*
   2018/06/22
   unsiged int 和 int之间的运算.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

/********************unsigned int 和 int之间的运算规则****************************/
//当表达式中存在有符号类型和无符号类型时,所有的操作数都先自动转换为无符号类型(对于任何运算符都适用)
//所谓自动转成无符号是指首位不再做符号判断.
int main(void)
{
    unsigned int unsigned_var = 20;
    signed int signed_var = -1020;
    (unsigned_var > signed_var) ? puts("left") : puts("right");
    unsigned int i = unsigned_var + signed_var;
    printf("%u\n", i);
    /*
       right
       4294966296
    */
    system("pause");
    return 0;
}
