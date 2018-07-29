#ifndef _STUDENT_H_
#define _STUDENT_H_

#define NAME_MAX 128

typedef struct
{
    char name[NAME_MAX];
    int age;
    char sex;
} student;

int creat_array(student **st, int count);
void desty_array(student **st);
void sort_fun(student * st, int count);
void erg_fun(student * st, int count);

#endif
