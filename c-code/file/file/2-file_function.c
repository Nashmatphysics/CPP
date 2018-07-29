/*
2018/07/03

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

/***********************************fgets() & fputs*************************************/
//文件<---字符串---->内存.
int main1(void)
{
	FILE *fp = NULL;
	fp = fopen("nash.txt", "w+");//w+: 不管是读还是写, 都先清空文件内容
	if (fp == NULL)
	{
		printf("open file error\n");
		return -1;
	}
	char str[128] = { 0 };
	char *count = NULL;
	//printf("%d\n", fputs("nash", fp));//fputs写成功返回0, 失败返回EOF
	//rewind(fp);//读写指针移到开始, 一定要注意读写指针的位置.
	count = fgets(str, 20, fp);//从文件读数据到内存, 遇到换行,文件尾, <size-1时结束, 当从文件尾开始继续读时,出错.
	//返回值:gets()若成功则返回字符串地址,返回NULL则表示有错误发生
	printf("str: %s\t count: %p\n", str, count);
	fclose(fp);

	//getchar();
	system("pause");
	return 0;
}
/**********************************文件copy(只能copy字符串)**************************************/
int main1_2(int argc, char *argv[])
{

	FILE *fp, *fq;
	char a[4069] = { 0 };
	if (argc < 3)
	{
		printf("文件操作数量过少\n");
		return -1;
	}

	fq = fopen(argv[1], "r");
	fp = fopen(argv[2], "w");

	if ((!fp) || (!fq))//只要有一个打开失败就终止.
	{
		printf("open file error\n");
		return -1;
	}

	while (fgets(a, sizeof(a), fq) != NULL)//利用数组a作为中转区.
	{
		fputs(a, fp);
	}
	system("pause");
	return 0;
}

/***********************************fread & fwrite*************************************/
//二者读写的是原汁原味的二进制数据.fread和fwrite函数一般用于二进制文件的输入输出----->可以读写任何数据类型.
//返回值：读或写的记录数，成功时返回的记录数等于nmemb，出错或读到文件末尾时返回的记录数小于nmemb，也可能返回0。
//二进制读写的程序不可跨平台移植
int main2(void)
{
	FILE *fp = NULL;
	fp = fopen("nash2.txt", "w+");
	if (fp == NULL)
	{
		printf("open file error\n");
		return -1;
	}
	char str[128] = { 0 };
	printf("%d\n", fwrite("nash", 1, 3, fp));//fwrite成功返回写的元素的个数,失败返回0
	rewind(fp);
	printf("%d\n", fread(str, 1, 3, fp));//fwrite成功返回读到的元素的个数,失败返回0
	printf("%s\n", str);

	system("pause");
	return 0;
}
//将结构体写入文件,并读出
struct record
{
	char name[10];
	int age;
};
//写入
int main_w(void)
{
	struct record array[2] = { {"Ken", 24}, {"Knuth", 28} };
	FILE *fp = fopen("nash4", "w");
	if (fp == NULL) {
		perror("Open file recfile");
		exit(1);
	}
	fwrite(array, sizeof(struct record), 2, fp);
	fclose(fp);
	system("pause");
	return 0;
}
//读取
int main_r(void)
{
	struct record array[2];
	FILE *fp = fopen("nash4", "r");
	if (fp == NULL)
	{
		perror("Open file recfile");
		exit(1);
	}
	fread(array, sizeof(struct record), 2, fp);
	printf("Name1: %s\tAge1: %d\n", array[0].name, array[0].age);
	printf("Name2: %s\tAge2: %d\n", array[1].name, array[1].age);
	fclose(fp);
	system("pause");
	return 0;
}
/***********************************fcsanf & fprintf*************************************/
//fscanf和fprintf非二进制读写.----->到文件中的都是字符(但是可以通过fscanf格式化参数转为其他数据类型)
//跟printf和scanf一样.
int main3(void)
{
	FILE *fp = NULL;
	fp = fopen("nash3.txt", "w+");
	if (fp == NULL)
	{
		printf("open file error\n");
		return -1;
	}
	printf("%d\n", fprintf(fp, "hello %d", 5));//返回值:成功时返回输出的字节数,失败时返回EOF
	rewind(fp);

	char str[128] = { 0 };
	printf("%d\n", fscanf(fp, "%s", str));//成功返回成功读到的次数, 失败返回EOF
	printf("%s\n", str);

	fclose(fp);
	system("pause");
	return 0;
}
/***********************************利用fseek扩展文件.*************************************/
int main4(void)
{

	FILE *fp = NULL;
	fp = fopen("itcast", "w+");

	//fseek(fp, -1, SEEK_SET);
	fseek(fp, 1000, SEEK_END);//将读写指针移到距离文件尾1000个字节的地方.
	fputc('\0', fp);		//必须有一次写操作才能真正拓展文件
	//这时文件大小为1001字节.
	fclose(fp);
	system("pause");
	return 0;
}
/*
总结:
易错点:
1.同一个文件读写时,容易忽略当前读写指针的位置对文件读写的影响.
*/
/***********************************sprintf&sscanf*************************************/
int main5(void)
{
	char array[1024] = { 0 };
	int i = 0;
	scanf("%d", &i);
	sprintf(array, /*sizeof(array),*/ "%d", i);//将格式化数据复制给字符串, 遇到\0结束接收,指定的字符个数包括\0
	printf("%s", array);
	snprintf(array, sizeof(array), "na\0sh");//'\0'在格式化参数中是适用的.
	/*_CRT_STDIO_INLINE int __CRTDECL snprintf(
    _Out_writes_z_(_BufferCount)  char*       const _Buffer,
    _In_                          size_t      const _BufferCount,
    _In_z_ _Printf_format_string_ char const* const _Format,
    ...)*/
	/*
	总结:
	1.推荐snprintf()
	2.对格式化参数的理解: 格式化参数本质是一个c风格的字符串, char const*类型, 所以其结尾一定是\0, 包含格式化参数的函数一般都是以\0作为结束接收标志.
	3.snprintf()可以用来将数字转成字符串.
	*/

//getchar();
system("pause");
return 0;
}

/***********************************_fileno*************************************/
//返回文件流所使用的文件描述符
int main6(void)
{
	FILE * fp;
	int fd;
	fp = fopen("nash.txt", "r");
	fd = _fileno(stderr);
	printf("fd = %d \n", fd);
	fd = _fileno(stdin);
	printf("fd = %d \n", fd);
	fd = _fileno(stdout);
	printf("fd = %d \n", fd);
	fd = _fileno(fp);
	printf("fd = %d \n", fd);
	fclose(fp);
	system("pause");
	return 0;
}
//注意: posix标准的是fileno()函数.