/*
   2018-06-23
   求两个数的最大公约数 
   */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

/***********************************方法1---常规方法.*************************************/
int my_max(int left, int right);
int my_min(int left, int right);
int if_divisor(int left, int right);

int main1(void)
{
    int m=0, n=0, i=0, j=0, k=0;
    scanf("%d %d", &m, &n);
    k = my_max(m, n);
    i = my_min(m, n);
    for(j=i; j>=1; --j)
    {
        if(if_divisor(j, i))
        {
            if(if_divisor(j, k))
                break;
        }
    }
    if(j != 0)
        printf("%d's maxium divisor is %d\n", i, j);

    system("pause");
    return 0;
}

int my_max(int left, int right)
{
    if(left >= right)
        return left;
    else
        return right;
}

int my_min(int left, int right)
{
    if(left >= right)
        return right;
    else
        return left;
}

int if_divisor(int left, int right)//形参没有起好
{
    if((right%left)==0)
        return 1;
    else
        return 0;
}

/***********************************方法2-*************************************/
//辗转相除法
int main(int argc, char *argv[])
{
    int m=0, n=0, i = 0, r = 0;
    scanf("%d %d", &m, &n); 
    if(m < n)
    {
        i = m;
        m = n;
        n = i;
    }
    r = m%n;
    while(r != 0)
    {
        m = n;
        n = r;
        r = m%n;//最大公约数是第一个能除清时的除数.
    }
    printf("%d\n", n);

	system("pause");
    return 0;
}
