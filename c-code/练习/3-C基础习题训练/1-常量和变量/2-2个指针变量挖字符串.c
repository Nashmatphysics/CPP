/*
Enter a date(mm/dd/yyyy): 10/11/2012
output the date: 20121011
2018/07/07
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <windows.h>
/***********************************way1*************************************/
//2个指针变量挖字符串.
#define DATE_LINE 128

int dig_string(/*这里为什么不能加const?*/char *source, char dest[10][32], const char ch, int *count)
{
	char *p = NULL;
	char *temp_p = NULL;
	int temp_count = 0;

	temp_p = p = source;
	while (*p != 0)//p没有在尾部的情况.
	{
		//p = strchr(source, ch);//error, why?------------>循环将永远从开始查找子串!
		p = strchr(p, ch);
		if (p != NULL)//1.找到/的情况
		{
			if ((p - temp_p) != 0)//2.最一般的情况.
			{
				strncpy(dest[temp_count], temp_p, p - temp_p);
				p++;
				temp_p = p;
				temp_count++;
			}
			else//3.当前位置就是/的情况
			{
				p++;
				temp_p = p;
			}
		}
		else//4.找不到/的情况.
		{
			strncpy(dest[temp_count], temp_p, strlen(temp_p));
			temp_count++;
			break;
		}
	}
	*count = temp_count;

	return 0;
}

int main(void)
{
	char input_date[DATE_LINE] = "";
	char output_date[10][32] = { "" };
	int count = 0;//子串个数
	char ch = '/';

	printf("Enter a date(mm/dd/yyyy): 10/11/2012:\n");
	//scanf("%s", input_date);
	strcpy(input_date, "10/11/2012");
	//printf("%s\n", input_date);
	int ret = 0;
	ret = dig_string(input_date, output_date, ch, &count);
	if (ret != 0)
	{
		printf("dig_string error\n");
		return -1;
	}
	/*
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", output_date[i]);
	}
	*/
	printf("%s%s%s", output_date[2], output_date[0], output_date[1]);
	
	system("pause");
	return 0;
}
/*
总结:
调试技巧:
出现问题后, 先看看出问题的地方,各个指针所指向的内存的值有没有问题, 指针指向有没有问题.
*/