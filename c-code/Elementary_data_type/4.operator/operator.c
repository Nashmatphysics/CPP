/*
2018/06/22
运算符
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

/*********************************** division(/) *************************************/
int main1(void)
{
    //除法：当对象都是int，则结果也是int,去掉小数部分保留整数部分,且不经过四舍五入；
    //当对象中只要有一个浮点型数据，则结果就是浮点型数据。
    double outcome = 0.0;
    outcome = 20 / 3; //=的运算顺序是从右往左, 20 / 3 --> 6(int), 再经过隐式类型转换为double--->6.000000
    printf("int: %f\n", outcome); //float和double都是%f
    outcome = 20 / 3.0;
    printf("double: %f\n", outcome);
    /*
    int: 6.000000
    double: 6.666667
    */

/*********************************** 取余% *************************************/
    //取余：左右运算对象必须都是整型，且结果的正负与被除数相同, 与除数无关.
    int result = 0;
    result = 5 % 2;
    printf("取余: %d\n", result);
    result = -5 % 2;
    printf("取余-: %d\n", result);

    system("pause");
    return 0;
}

/***********************************logic operator*************************************/
//逻辑运算符的结果只能是逻辑值，即真或假(C语言中存储为1和0)。
//顺序为从左到右.
//一律使用括号指定优先级
//逻辑操作符的目的不在于运算,而是判断表达式的真假, 一旦在运算的过程中真假确定, 则运算停止.
int main2(void)
{
    /*短路问题*/
    //&&
    //逻辑与操作符，左操作数为假，右操作数被短路
    printf("&&:\n");
    if (0 && (printf("right0\n")))
        ;
    if (1 && (printf("right1\n")))
        ;

    //||
    //逻辑或造成的短路操作，左操作数为真，右操作数被短路
    printf("||:\n");
    if (0 || (printf("right0\n")))
        ;
    if (1 || (printf("right1\n")))
        ;

    system("pause");
    return 0;
}

/********************************三目运算符(条件运算符)********************************/
//c语言中唯一一个三目运算符
//语句1? 语句2: 语句3
//先执行语句1,若结果为真,则执行语句2;结果为假,执行语句3
//相当于一个if...else判断语句
int main3(void)
{
    2 > 3 ? puts("left") : puts("right");
    system("pause");
    return 0;
}

/***********************************自增自减运算符*************************************/
int main(void)
{
    /*
    2种情况下: i = i+1;
    j = ++i; ---> j = i+1;
    j = i++; ---> j = i;//这里的i是+1之前的i.
    */
    int i = 0, j = 0;
    j = ++i;
    printf("j = %d\ti = %d\n", j, i);
    i = 0;
    j = i++;
    printf("j = %d\ti = %d\n", j, i);
    /*  j = 1   i = 1
        j = 0   i = 1
    */
    system("pause");
    return 0;
}
