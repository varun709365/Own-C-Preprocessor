#include "header.h"
void comment(FILE *fs){
        char **s,ch,ch2;
        int l=0,i,j;
        while((ch=fgetc(fs))!=EOF){
                if(ch=='\n')
                        l++;
        }
        rewind(fs);
        s=malloc(sizeof(char *)*l);
        for(i=0;i<l;i++)
                s[i]=malloc(sizeof(char)*100);
        i=0;
        j=0;
        while((ch=fgetc(fs))!=EOF){
                if(ch=='\n'){
                        s[i][j]='\n';
                        ch2=0;
                        i++;
                        j=0;
                }
                else if(ch=='/'){
                        ch2=fgetc(fs);
                        if(ch2=='/'){
                                while((ch=fgetc(fs))!=EOF)
                                        if(ch=='\n')
                                                break;
                                s[i][j]='\n';
                                i=i++;j=0;
                        }
                        else if(ch2=='*'){
                                while((ch=fgetc(fs))!=EOF){
                                        if(ch=='*'){
                                                if((ch2=fgetc(fs))=='/'){
                                                        s[i][j]='\n';
                                                        i=i++;j=0;
                                                        break;
                                                }
                                        }
                                }
                        }
                        else
                                s[i][j++]=ch2;
                }
                else
                        s[i][j++]=ch;
        }
        rewind(fs);
        fs=fopen("temp.c","w");
        for(i=0;i<l;i++)
                fprintf(fs,"%s",s[i]);
        rewind(fs);
}