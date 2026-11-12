#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void header(FILE *fs,FILE *fp){
        char s[20],t[]="#include",t2[]="main",h[20],path[50]="/usr/include/",h1[100];
        int len,i=0,f=0,hlen;
        FILE *fh;
        fscanf(fs,"%s",s);
        if(f==1){
                strncpy(path,path,13);
                path[13]='\0';
                f=0;
        }
        if(strncmp(t,s,8)==0){
                len=strlen(s);
                if(len==8){
                        fscanf(fs,"%s",h);
                }
                else{
                        sscanf(s+8,"%s",h);
                }
                while(h[i]){
                        h[i]=h[i+1];
                        i++;
                }
                h[i-2]=h[i-1];
                i=0;
                fh=fopen(h,"r");
                if(fh==0){
                        strcat(path,h);
                        fh=fopen(path,"r");
                        f=1;
                }
                while(fgets(h1,100,fh)!=NULL)
                        fputs(h1,fp);

        }
}