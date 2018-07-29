/*
   2018-06-23
   判定是否为闰年
   */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

int main1(void)
{
    int year = 0;
    printf("please enter year:\n");
    scanf("%d", &year);
    if ((year <= 2000) || (year >= 2500))
    {
        printf("enter error\n");
        system("pause");
        return 0;
    }

    if ((year % 4 == 0))
    {
        if ((year % 100) == 0)
        {
            if (year % 400 == 0)
                printf("%d is 闰年\n", year);
            else
                printf("%d is not 闰年", year);
        }
        else
            printf("%d is 闰年", year);
    }
    else
        printf("%d is not 闰年", year);

    system("pause");
    return 0;
}
/*  main1有什么问题?
 *  1.多层嵌套.
 *  2.层次不清, 导致代码一窝粥----->使用函数分层.
 */
/**********************改进***************************/
int if_leap_year(int year);

int main(int argc, char *argv[])
{
    int year = 0;

    for(int year = 2000; year <= 2500; ++year)
    {
        if (if_leap_year(year))
            printf("%d is leap year\n", year);
        else
            continue;
        //printf("%d is leap not year\n", year);
    }

END:
    system("pause");
    return 0;
}

int if_leap_year(int year)
{
    int i = 0;
    if ((year % 4 == 0))
    {
        if ((year % 100) == 0)
        {
            ((year%400) == 0)? (i=1): (i=0);//必须加括号
        }
        else
            i = 1;
    }
    else
        i = 0;
    return i;
}



