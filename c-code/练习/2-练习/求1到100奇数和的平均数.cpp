/*
2018-06-22
1到100奇数和的平均数
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

int main(void)
{
    int i = 0, count = 0;
    int sum = 0;
    double adv = 0;
    for(i = 1;i<=100;++i)
    {
        if((i%2) != 0)
        {
            count++;
            sum += i;
        }
    }
    adv = ((double)sum) / count;
    printf("%f", adv);
    
    system("pause");
    return 0;
}