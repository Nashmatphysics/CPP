# C 常用库函数
[TOC]

## math.h
### double sqrt(double x)
计算x的平方根(x >= 0)

### double pow(double x, double y)
功能：计算x^y的值
返回值：计算结果
举例：
```
double a;
a = pow(3.14, 2);  // 计算3.14的平方，并将结果保存在变量a中
```
注：
使用pow函数必须将头文件#include<math.h>包含进源文件中
像 pow(10,2) 这种调用，gcc 在编译时就可以将其替换为对应的值（gcc 优化的一部分），从而不需要链接 pow 所在的数学库 libm；而像 pow(x,2); 这种调用，一般无法做这种替换，因此需要链接 libm。或者编译时加上-O2参数。
```
gcc test.c -o app -lm
gcc test.c -o app -O2
```

### double ceil(double x)
求不小于x的最小整数，并以double形式显示

### double floor(double x)
求不大于x的最大整数，并以double形式显示

### int abs(int x)
求整数x的绝对值

### double fabs(double x)
求实数x的绝对值

## ctype.h
### int toupper(int x)
如果x为小写字母，则返回对应的大写字母
返回转换后的大写字母，若不须转换则将参数c值返回。

### int tolower(int x)
如果x为大写字母，则返回对应的小写字母
返回转换后的小写字母，若不须转换则将参数c值返回。

## stdlib.h
### rand()
int rand(void)
随机数产生器.
必须先利用srand（）设好随机数种子
返回0至RAND_MAX之间的随机数值，RAND_MAX定义在stdlib.h.

void srand (unsigned int seed);
参数seed必须是个整数，通常可以利用geypid（）或time（0）的返回值来当做seed
如果每次seed都设相同值，rand（）所产生的随机数值每次就会一样。
```
#include<time.h>
#include<stdlib.h>
main()
{
  int i,j;
  srand((int)time(0));
  for(i=0;i<10;i++)
  {
   j=1+(int)(10.0*rand()/(RAND_MAX+1.0));
   printf(“ %d “,j);
}
}
```
### void exit(int retval)
终止程序

### extern void *malloc(unsigned int num_bytes)
malloc函数是一种分配长度为num_bytes字节的内存块的函数(memory allocation:动态内存分配),void* 表示未确定类型的指针。C,C++规定，void* 类型可以通过类型转换强制转换为任何其它类型的指针

### void *memset(void *s, int c, size_t n)
memset()会将参数s所指向的内存区域前n个字节以参数c填入，然后返回指向s的指针。在编写程序时，若需要将某一数组作初始化，memset()会相当方便。

### int atoi(const char *nptr)
将字符串数字转换成真正的数字
atoi()会扫描参数nptr字符串，跳过前面的空格字符，直到遇上数字或正负符号才开始做转换，而再遇到非数字或字符串结束时（’\0’）才结束转换,返回转换后的整型数。

### void * memcpy (void * dest ,const void *src, size_t n)
拷贝src所指的内存内容前n个字节到dest所指的内存地址上。与strcpy（）不同的是，memcpy（）会完整的复制n个字节，不会因为遇到字符串结束‘\0‘而结束, 返回指向dest的指针
注意:
1.指针src和dest所指的内存区域不可重叠.
2.使用时, 最好使用(void*)进行强制类型转换.

## unistd.h
### usleep sleep

## stdio.h
### 输入输出函数.
#### sprintf sscanf 
以字符串作为输入输出的对象.
int sprintf( char *str,const char * format,.........);
成功则返回参数str字符串长度，失败则返回-1，错误原因存于errno中。
使用此函数得留意堆栈溢出，或改用snprintf（）
int sscanf (const char *str,const char * format,........);
成功则返回参数数目，失败则返回-1，错误原因存于errno中
#### fprintf  fscanf
以文件作为输入输出的对象.

## time.h
### time()
time_t time(time_t *calptr);
返回1970-1-1, 00:00:00以来经过的秒数
结果可以通过返回值，也可以通过参数得到，见实例
返回值: 
  成功：秒数，从1970-1-1,00:00:00 可以当成整型输出或用于其它函数
  失败：-1
例:
    time_t now;//time_t 本质是long long类型的数据(%lld)
    time(&now);// 等价于: now = time(NULL)
    printf("now time is %d\n", now);
 
### localtime()
struct tm *localtime(const time_t * calptr); 
将时间数值变换成本地时间，考虑到本地时区和夏令时标志;
返回值:
    成功: 返回struct tm *结构体指针, 原型如下:
       struct tm {
              int tm_sec;       /* 秒 – 取值区间为[0,59] */ 
              int tm_min;       /* 分 - 取值区间为[0,59] */ 
              int tm_hour;      /* 时 - 取值区间为[0,23] */ 
              int tm_mday;     /* 一个月中的日期 - 取值区间为[1,31] */ 
              int tm_mon;     /* 月份（从一月开始，0代表一月） - 取值区间为[0,11] */ 
              int tm_year;     /* 年份，其值等于实际年份减去1900 */ 
              int tm_wday;    /* 星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一 */ 
              int tm_yday;    /* 从每年1月1日开始的天数– 取值区间[0,365]，其中0代表1月1日 */ 
              int tm_isdst;    /* 夏令时标识符，夏令时tm_isdst为正；不实行夏令时tm_isdst为0 */    
       };
    注意: 内核自动创建了一个struct tm结构体变量, 我们只需要定义struct tm*指针即可, 也不需要我们去释放这个结构体变量
    失败: NULL
例:
    time_t now ;
    struct tm *tm_now ;
    time(&now) ;
    tm_now = localtime(&now) ;
    printf("now datetime: %d-%d-%d %d:%d:%d\n", tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec) ;

具体操作函数
包含文件:<sys/time.h> <time.h> 
```
struct tm *gmtime(time_t * t);//与localtime()基本相同.
char *asctime(const struct tm *timeptr);//格式: "Wed Jun 30 21:49:08 1993\n"
char *ctime(const time_t *timer); //格式: "Wed Jun 30 21:49:08 1993\n"
```
把tm指针转换为time_t
time_t mktime(struct tm *timeptr);
localtime和gmtime的区别在于gmtime将时间转换为国际标准格式，也就是相对于1970 00:00:00开始的时间戳
而localtime是相对于本地的时区的格式。
```
#include<stdio.h>
#include<time.h>
#include<sys/time.h>
#include<signal.h>
#include<pthread.h>
void quit_t()
{
        printf("eixt now");
        exit(-1);
}
int main()
{
/*      struct timeval  vt;
        gettimeofday(&vt , NULL);
        while(1)
        {
                printf("%u:%u\n",vt.tv_sec,vt.tv_usec);
                sleep(2);
                signal(SIGINT, quit_t);
        }
*/

        struct tm *tt;
        time_t t = time(NULL);
        tt = gmtime(&t);
        //char *s = asctime(tt);
        printf("%d-%d-%d %d:%d:%d",tt->tm_year+1900,tt->tm_mon+1,tt->tm_mday,tt->tm_hour,tt->tm_min,tt->tm_sec);
        return 0;
}
```

## limits.h
limits.h专门用于检测整型数据数据类型的数值范围.
要判断某种特定类型可以容纳的最大值或最小值，一种简便的方法是使用ANSI标准头文件limits.h中的预定义值。该文件包含一些很有用的常量，它们定义了各种类型所能容纳的值，下表列出了这些常量：
```
CHAR_BIT char的二进制位数(bit)
CHAR_MAX char的有符号整数最大值
CHAR_MIN char的有符号整数最小值
MB_LEN_MAX 多字节字符的最大字节(byte)数
INT_MAX int的有符号最大值
INT_MIN int的有符号最小值
LONG_MAX long的十进制最大值
LONG_MIN long的十进制最小值
SCHAR_MAX signedchar的十进制整数最大值
SCHAR_MIN signedchar的十进制整数最小值
SHRT_MIN short的十进制最小值
SHRT_MAX short的十进制最大值
UCHAR_MAX unsignedchar的十进制整数最大值
UINT_MAX unsignedint的十进制最大值
ULONG_MAX unsignedlongint的十进制最大值
USHRT_MAX unsignedshortint的十进制最大值
```
对于整数类型，在使用2的补码运算的机器(你将使用的机器几乎都属此类)上，一个有符号类型可以容纳的数字范围为:
```
[- 2^(位数-1) ]到[+ 2^(位数 -1)-1]
```
一个无符号类型可以容纳的数字范围为:
```
0到(+ 2^位数 )。
```
例如，一个16位有符号整数可以容纳的数字范围为:
```
-2^15(即-32768)到(+2^15-1)(即+32767)
```
而16为无符号整数可容纳的最大值为`(2^位数-1)`或表示为汇编形式0xffff。

## sleep()
关于sleep()函数在windows系统和linux系统下是两个不同的函数，差别较大，但功能是相同的，都是将进程挂起一段时间。

windows系统下函数名为Sleep(),其函数原型为：
函数使用头文件: <windows.h> 
void Sleep(DWORD dwMilliseconds);  参数为毫秒
参考代码：
```
#include <windows.h> //win头文件
#include<stdio.h>
int main()
{
    int i;
    printf("你");
    fflush(stdout); //强制刷新缓存，输出显示
    for( i=0;i<10;i++ )
    {
        Sleep(1000);    /* windows 使用Sleep，参数为毫秒 */
        printf(".");
        fflush(stdout);//强制刷新缓存，输出显示
    }
    printf("好\n");  //输出“你”和“好”之间会间隔10秒,并输出10个点
    return 0;
}
```

linux系统下函数名为sleep(),其函数原型为：
函数使用头文件: <unistd.h>  
unsigned int sleep(unsigned int seconds);参数为毫秒 （如果需要更精确可以用usleep，单位为微秒）

修改上面的代码，以适应linux系统:
```
#include <unistd.h>  //1、linux 头文件
#include<stdio.h>
int main()
{
    int i;
    printf("你");
    fflush(stdout);//强制刷新缓存，输出显示
    for( i=0;i<10;i++ )
    {
        sleep(1);       /*2、linux 使用sleep，参数为秒*/
        printf(".");
        fflush(stdout);//强制刷新缓存，输出显示
    }
    printf("好\n"); /*输出“你”和“好”之间会间隔10秒,并输出10个点*/
    return 0;
}
```
