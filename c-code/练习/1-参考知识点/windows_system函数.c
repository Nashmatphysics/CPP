/*
system函数的使用
*/
#define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <stdlib.h>
//stdlib.h和stdio.h两个包含的函数完全不同,stdlib和malloc才是兼容关系, 推荐使用stdlib
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

int main1(void)
{
	int i;
	printf("hello world\n");
	scanf("%d", &i);
	getchar();//建议输入函数后面都添加getchar(),可以过滤回车
	printf("%d", i);

	system("color 6A");
	/*
	调用color函数可以改变控制台的前景色和背景，具体参数在下面说明。
	例如，用 system("color 0A"); 其中color后面的0是背景色代号，A是前景色代号。各颜色代码如下：
	0=黑色 1=蓝色 2=绿色 3=湖蓝色 4=红色 5=紫色 6=黄色 7=白色 8=灰色 9=淡蓝色 A=淡绿色 B=淡浅绿色 C=淡红色 D=淡紫色 E=淡黄色 F=亮白色*/
	system("pause");//冻结屏幕, 便于观察运行结果(开始执行(不调试)即包含此功能)
	system("CLS");//清屏操作
	return 0;
}
/*
总结:
1.system函数的作用:
接收字符串, 并将接收到的内容发送到控制台/终端,作为命令执行,所以虽然c中有system函数,但system中的命令参数是不能通用的.
2.其声明在stdlib.h中
*/
/***********************************system实现关机程序*************************************/
int print(void)
{
	printf("C语言关机程序\n");
	printf("1.实现10分钟内的定时关闭计算机\n");
	printf("2.立即关闭计算机\n");
	printf("3.注销计算机\n");
	printf("0.退出系统\n");
	return 0;
}

int main(void)
{
	system("date /T");//?
	system("TIME /T");//?
	system("color 0B");//设置字体颜色
	system("mode con cols=48 lines=25");//设置窗口尺寸
	system("title C语言关机程序");
	print();
	short int i;
	scanf("%hd", &i);
	getchar();
	char cmd[20] = "shutdown -s -t";
	char t[5];
	switch (i)
	{
	case 1: printf("你想在多少秒后自动关机?\n"); scanf("%s", t); strcat(cmd, t);
		system(cmd); break;
	case 2: system("shutdown -p"); break;
	case 3: system("shutdown -l"); break;
	case 0: break;
	default: printf("Error!\n");
	}

	system("pause");
	exit(0);
}