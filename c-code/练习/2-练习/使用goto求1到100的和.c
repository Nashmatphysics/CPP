/*
   2018/06/22
   使用goto求1到100的和
   */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

//方法1
int main1(void)
{
    int i = 0, sum = 0;

BEGIN:
    sum += i;
    i++;
    if(i <= 100)
        goto BEGIN;
    printf("sum: %d\n", sum);
    //getchar();
    system("pause");
    return 0;
}

//方法2
int main(int argc, char *argv[])
{
    int i = 0, sum = 0; 
BEGIN:
    if(i<=100)//先定边界条件,再定循环体, 最后定循环范围(也算循环体的一部分吧)
    {
        sum += i;
        i++;
        goto BEGIN;
    }
       printf("sum: %d\n", sum); 
       system("pause");
    return 0;
}
//哪种好?
//第二种--->代码块清晰.
