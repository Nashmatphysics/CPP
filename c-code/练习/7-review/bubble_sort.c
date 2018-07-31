/*
2018/7/28
 review
 bubble sort
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
//#include <stdarg.h>

#define NUM 24

int creat_rand(int *array, int size);
void travel_fun(int *array, int size);
void sort_fun(int *array, int size);

int main(void)
{
    //creat a array
    int * my_array = NULL;
    my_array = (int *)malloc(NUM * sizeof(int));
    int ret = 0;
    ret = creat_rand(my_array, NUM);
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

static int creat_rand(int *array, int size)
{
    int ret = 0;
    if((array == NULL) || (size <= 0))
    {
        printf("input error\n");
        ret = -1;
        goto END;
    }
    srand((unsigned int)time(NULL));//srand need a parameter as a seed;
    for(int i = 0; i < size; ++i)
    {
        array[i] = rand() % 100;
    }
    END:
    return ret;
}

static void travel_fun(int *array, int size)
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

static void sort_fun(int *array, int size)
{
    if((array == NULL) || (size <= 0))
    {
        printf("input error\n");
        return ;
    }

    for(int i = 1; i < size; ++i)
    {
       for(int j = 0; j < (size - i); ++j)
       {
           if(array[j] < array[j+1])
           {
           int temp = 0;
           temp = array[j];
           array[j] = array[j+1];
           array[j+1] = temp;
           }
       }
    }
}
