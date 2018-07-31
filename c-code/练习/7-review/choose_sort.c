//
// Created by NASH on 2018/7/28.
//
/*
2018/7/28
选择排序
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

#define NUM 24

int creat_rand(int **array, int size);
void travel_fun(int *array, int size);
void sort_fun(int *array, int size);

int main(void)
{

    //creat a array
    int * my_array = NULL;

    int ret = 0;
    ret = creat_rand(&my_array, NUM);
    if(ret != 0)
    {
        printf("creat_rand error\n");
        return -1;
    }

    travel_fun(my_array, NUM);
    printf("=========================\n");

    sort_fun(my_array, NUM);

    travel_fun(my_array, NUM);
    printf("=========================\n");

//getchar();
system("pause");
return 0;
}

void change_fun(int *left, int *right)
{
   if((left == NULL) || (right == NULL))
   {
       printf("input error\n");
       return ;
   }
   int temp = 0;
   temp = *left;
   *left = *right;
   *right = temp;
}

int creat_rand(int **array, int size)
{
    int ret = 0;
    if((array == NULL) || (size <= 0))
    {
        printf("input error\n");
        ret = -1;
        goto END;
    }

    int *temp_array = NULL;

    temp_array = (int *)malloc(NUM * sizeof(int));
    if(temp_array == NULL)
    {
        printf("malloc failed\n");
        ret = -2;
        goto END;
    }

    srand((unsigned int)time(NULL));//srand need a parameter as a seed;
    for(int i = 0; i < size; ++i)
    {
        temp_array[i] = rand() % 100;
    }
    *array = temp_array;

    END:
    return ret;
}

void travel_fun(int *array, int size)
{
    if((array == NULL) || (size <= 0))
    {
        printf("input error\n");
        return ;
    }
    for(int i = 0; i < size; ++i)
    {
        printf("%d\t", array[i]);
    }
    putchar('\n');
}
void sort_fun(int *array, int size)
{
    if((array == NULL) || (size <= 0))
    {
        printf("input error\n");
        return ;
    }
   int sm = 0;
    for (int j = size-1; j > 0 ; --j)
    {

    for (int i = 0; i < j + 1; ++i)
    {
        if(array[sm] < array[i])
        {
            sm = i;
        }
    }

    change_fun(array+j, array+sm);
    //array[j] = array[sm];
    }
}

