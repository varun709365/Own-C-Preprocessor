#include "header.h"
void prepro(FILE *fs,FILE *fp,sll **hptr){
        char s[]="#include",s2[]="#define",s3[]="main",t[20];
        int len;
        while(fscanf(fs,"%s",t)>0){
                len=strlen(t);
                if(strncmp(s,t,8)==0){
                        fseek(fs,-len,SEEK_CUR);
                        header(fs,fp);
                }
                else if(strncmp(s2,t,7)==0){
                        fseek(fs,-len,SEEK_CUR);
                        macro(fs,hptr);

                }
                else if(strstr(t,s3)){
                        fputs(t,fp);
                        break;

                }
                else{
                        fputs(t,fp);
                        fputc(' ',fp);
                }
        }
}
