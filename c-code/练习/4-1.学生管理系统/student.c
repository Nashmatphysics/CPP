#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>
#include "student.h"

int creat_array(student ** st, int count)
{
    student *temp = NULL;
    int ret = 0;
    if((st == NULL) || (count <= 0))//为什么是st, 而不是*st?
    {
        ret = -1;
        printf("creat_array: input error\n");
        goto END2;
    }

    temp = (student *)malloc(count * sizeof(student));
    if(temp == NULL)
    {
        ret = -2;
        printf("creat_array: malloc failed\n");
        goto END2;
    }
    memset(temp, 0, count * sizeof(student));
    *st = temp;

END2:
    return ret;
}

void desty_array(student **st)
{
    if(st == NULL)
    {
        printf("desty_array: input error\n");
        return;
    }

    if(*st != NULL)
    {
        free(*st);
        *st = NULL;
    }
}
void sort_fun(student * st, int count)
{
    if((st == NULL) || (count <= 0))
    {
        printf("sort_fun: input error\n");
        return ;
    }
    for (int i = 1; i < count; ++i)
    {
        for (int j = 0; j < (count-i); ++j)
        {
            if(st[j].age > st[j+1].age) 
            {
                int temp = 0;
                temp = st[j].age;
                st[j].age = st[j+1].age;
                st[j+1].age = temp;
            }
        }
    }
}
void erg_fun(student * st, int count)
{
    if((st == NULL) || (count <= 0))
    {
        printf("erg_fun: input error\n");
        return ;
    }
    for (int i = 0; i < count; ++i)
    {
        printf("第%d个学生的信息:\tname:%s\tage:%d\tsex:%c\n", i, st[i].name, st[i].age, st[i].sex);
    }
}
