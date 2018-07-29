/*
   2018/07/09
   学生信息管理系统
   ---------------------
   1.输入学生个数
   2.输入学生信息
   3.按学生年龄升序排序
   4.输出信息.
   */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>
#include "student.h"

int main(void)
{
    student * st_array = NULL;
    int count= 0;
    int ret = 0;

    printf("------------------------\n");
    printf("学生信息管理系统\n");
    printf("------------------------\n");
    printf("请输入学生个数:\n");
    scanf("%d", &count);

    ret = creat_array(&st_array, count);
    if(ret != 0)
    {
        printf("creat_array error\n");
        goto END;
    }

    for (int i = 0; i < count; ++i)
    {
       printf("请输入第%d个学生的信息:\n", i+1); 
       fscanf(stdin, "%s %d %c", st_array[i].name, &(st_array[i].age), &(st_array[i].sex));
	   //scanf("%s %d %c", st_array[i].name, &(st_array[i].age), &(st_array[i].sex));
	   getchar();
    }

    sort_fun(st_array, count);
    erg_fun(st_array, count);

    desty_array(&st_array);
END:
    system("pause");
    return ret;
}
