#ifndef _MYGUESS_H_
#define _MYGUESS_H_

#define RAND_NUM 10000
#define STR_LINE 128
#define NUM_LINE 4
#define GIVE_STR "I GIVE UP"

void to_dif(int *sourc);
int rand_num(void);
int judge_fun(char *str, int size);
/* 1: I GIVE UP
 * 2: number
 * 3: wrong input
 * */

int trans_num(char *str, int size);

//全部猜对返回1
int compare_fun(int in_num, int source_num, char *out_str);

//把数字转成数组.
void itoia(int *array, int num);


#endif
