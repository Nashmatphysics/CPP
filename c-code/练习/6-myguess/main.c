/*
   2018/07/09
   猜字谜
   */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>
#include <time.h>
#include <stdarg.h>
#include "myguess.h"

#define STR_LINE 128

int main(void)
{
	printf("=========================================================\n");
	printf("猜字谜\n");
	printf("=========================================================\n");
    int sourc_num = 0;
    int in_num = 0;//输入字符转成的数字.
    char in_str[STR_LINE];
    char out_str[STR_LINE];
	//生成一个互不相等的四位数
    sourc_num = rand_num();//随机数生成函数有点问题, 有时不够4位数.
	printf("%d\n", sourc_num);

    //printf("请输入一个4位整数:\n");
    while(1)
    {
        int ret = 0;
        memset(in_str, 0, sizeof(in_str));
        memset(out_str, 0, sizeof(out_str));

        printf("玩家输入:\t");
        //scanf("%s", in_str);//scanf以空格作为分割, 所以不能使用scanf输入 I GIVE UP
		fgets(in_str, sizeof(in_str), stdin);//fgets()会将\n放到字符串中.所以要过滤掉.
		//getchar();
		char *p = NULL;
		if ((p = strchr(in_str, '\n')) != NULL)
		{
			*p = 0;
		}

        int judge = judge_fun(in_str, strlen(in_str));

        printf("程序提示:\t");
        switch(judge)
        {
            case 1: printf("%d\n", sourc_num); ret = 1;break;
            case 2: 
				in_num = atoi(in_str);
				//printf("%d\n", in_num);
				ret = compare_fun(in_num, sourc_num, out_str);
				printf("%s\n", out_str);
				break;
            case 3: 
				printf("input error, please enter again.\n"); break;
			default: printf("judge_func error\n");
        }
        if(ret == 1)
            break;
    }

    system("pause");
    return 0;
}
