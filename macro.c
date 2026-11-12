#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"
void macro(FILE *fs, sll **hptr){
        char s[100],t[20];
        int l=0;
        fgets(s,100,fs);
        if(*hptr==NULL){
                sll *node;
                node=malloc(sizeof(sll));
                sscanf(s+7,"%s",node->name);
                l=strlen(node->name);
                sscanf(s+7+l+2,"%s",node->value);
                node->next=NULL;
                *hptr=node;
                return ;
        }
        else{
                sll *node,*new;
                node=*hptr;
                while(node->next!=NULL)
                        node=node->next;
                new=malloc(sizeof(sll));
                sscanf(s+7,"%s",new->name);
                l=strlen(new->name);
                sscanf(s+7+l+2,"%s",new->value);
                new->next=NULL;
                node->next=new;
                return ;
        }

}


void repmacro(FILE *fs,FILE *fp,sll *hptr){
        sll *node;
        char *s,*t,f,ch='"',*r;
        int c,i,l=0;
        s=malloc(sizeof(char)*100);
        while(fgets(s,100,fs)>0){
                node=hptr;
                l=0;
                while(node!=NULL){
                        if((t=strstr(s+l,node->name))){
                                c=0;
                                i=0;
                                while(t[i]){
                                        if(t[i++]=='"')
                                                c++;
                                }
                                if ((c%2==0))
                                        mystrcat(s,t,node->value,node->name);
                                l=l+(t-s);
                        }
                        else{
                                node=node->next;
                                l=0;
                        }
                }
                fputs(s,fp);
        }
}
char* mystrcat(char *s,char *s2,char *v,char *name){
        char t[100],*temp;
        int len;
        len=strlen(name);
        strncpy(t,s,(s2-s));
        t[s2-s]='\0';
        strcat(t,v);
        strcat(t,s+(s2-s)+len);
        strcpy(s,t);
}
~