/*
   2018/07/08
   选择排序_and_递归排序
   */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>

void rand_fun(int array[], int count)
{
    srand((int)time(0));
    for (int i = 0; i < count; ++i)
    {
        array[i] = rand() % 100;
    }
}

void print_fun(int array[], int count)
{
    for (int i = 0; i < count; ++i)
    {
        printf("%d\n", array[i]);
    }
}

/***********************************递归排序*************************************/
void rec_sort_fun(int array[], int count)
{
    //终止条件
    if(count == 0)
        return;
    //执行体
    int max_t = 0;
    //找到最大元素的下标
    for (int i = 0; i < count; ++i)//循环结束时,i已经超出范围了
    {
        if(array[max_t]<array[i]) 
            max_t = i;
    }
    //并放到最后.
    int temp = array[max_t];
    array[max_t] = array[count-1];
    array[count-1]  = temp;
    //返回体
    //sort_fun(array, count--);//count永远是20----->why?-->count是个局部变量!后置--不会发生递减.
    rec_sort_fun(array, --count);
}

/***********************************选择排序*************************************/
void cho_sort_fun(int array[], int count)
{
    for (int i = count; i > 0; --i)
    {
        //找到最大元素的下标
        int max_t = 0;
        for (int j = 0; j < i; ++j)//循环结束时,i已经超出范围了
        {
            if(array[max_t]<array[j]) 
                max_t = j;
        }
        //并放到最后
        int temp = array[max_t];
        array[max_t] = array[i-1];
        array[i-1]  = temp; 
    }
}

int main(void)
{
    int array[20] = {0};
    rand_fun(array, 20);
    cho_sort_fun(array, 20);
    print_fun(array, 20);
    //getchar();
    system("pause");
    return 0;
}
/*总结:
 * 1.关于前置和后置--/++:
 *      一般不要利用二者差异的特性.
 *      一般情况下使用前置.
 *      要我说, 一般就不要使用这2个东西.
 * 2.关于选择排序.
 *      要点: 先找出最大元素的下标--->将这个最大元素放到尾部.
 * 3.关于递归.
 *      递归的2种模型:
 *      app: 终止条件-->app-->执行体    eg:利用递归实现栈.--->从最里层开始执行操作.
 *      app: 终止条件-->执行体-->app    eg:递归排序.---->每一层都执行了操作.
 */
