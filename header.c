#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void header(FILE  *,FILE *);
void mstrcat(char*,char*);
typedef struct stu{
        char name[20];
        char value[20];
        struct stu *next;
}sll;
char * mystrcat(char *,char *,char *,char *);
void repmacro(FILE *,FILE *,sll *);
void comment(FILE *);
void macro(FILE *,sll **);
void prepro(FILE *,FILE *,sll **);