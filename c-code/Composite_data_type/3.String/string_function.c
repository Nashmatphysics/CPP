#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>

/***********************************strcpy&strncpy的使用误区*************************************/
int main1(void)
{
    char array[1024] = {0};
    //strncpy(array, "nash", sizeof(array));//error, "nash"有sizeof(array)这么长吗!
    strncpy(array, "nash", sizeof("nash"));

    printf("%s\n", array);
    strncpy(array, "\0", sizeof(array));
    //strcpy(array, 0/*, sizeof(array)*/);//error, 0, 即NULL, strcpy会对NULL指向的空间进行读取操作--error.
    printf("%s\n", array);

    system("pause");
    return 0;
}
//注意: "nash" 代表的不是这个字符串, 而是它的地址

/***********************************puts() & gets()*************************************/
//有问题
/*
   puts("hello");//参数是字符串地址, 从首地址开始输出, 直到\0为止.
   puts(10);//这里的10被理解为首地址进行操作, 所以会发生错误
   puts();输出字符串后会自动换行
   */
int main2(void)
{
    puts("nash");
    //puts(10);error
    char a[128] = {0};
    //gets(a);//从键盘输入的所有字符都当做字符串字面值来接收.
    puts(a);
    /*
       nash
       nash123
       nash123
       请按任意键继续. . .
       */
    system("pause");
    return 0;
}

/***********************************strcat*************************************/
int main3(void)
{
	char str1[128] ="hello";
	char *str2 = "nash";
	char *str3 = "aaaaaaa";
	strcat(str1, str2);//将str2的数据copy到str1,与str1现有字符相接,str1的长度必须足够长
	printf("%s\n", str1);

	strncat(str1, str3, 3);//copy n个字符到str1
	printf("%s\n", str1);

	system("pause");
	return 0;
}
//总结:二者都有溢出隐患.

/***********************************strtok*************************************/
int main4_1(void)
{
    char str[] = "nash is good at mathematics";
    char *p = NULL;
    p = strtok(str, " ");
    printf("%s\n", p);
	while ((p = strtok(NULL, " ")) != NULL)
	{
		printf("%s\n", p);
	}

	system("pause");
	return 0;
}
/*
1.查找指定子串
2.将找到的子串替换成\0.
3.内部指针保存下一次要strtok的字符串地址
注意: 如果要从\0的后面开始继续分割, 则第一个参数必须为NULL, 表示从内置变量保存的地址开始继续分割.
返回值: 返回当前子串的地址, 如果分到字符串的结尾, 则返回NULL(只要没有到字符串的结尾, 即使没有要找的子串,也返回当前子串的地址, 所以很智能);
*/
int main(void)
{
	char str[] = "hello, world, itcast! good.; night?";
	char *dlim = " ,?!.;";
	char *p;

	p = strtok(str, dlim);
	printf("%s\n", p);
	while ((p = strtok(NULL, dlim)) != NULL)
		printf("%s\n", p);
	
	system("pause");
	return 0;
}
/*
hello
world
itcast
good
night
*/
//strtok并不是当指定字符串的所有字符都存在时才分割, 只要是指定子串中的字符就会分割.