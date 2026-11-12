#include "header.h"

int main(int argc,char **argv){
        FILE *fs,*fp,*ft;
        int l=0,b=0,i;
        char ch,temp[100],file[50],result[50];
if(argc!=2){
printf("myprocessor filename\n");
return 0;
}
strcpy(file,argv[1]);
strcpy(result,file);
i=0;
while(result[i]){
if(result[i]=='.')
break;
i++;
}
result[++i]='i';

        ft=fopen(file,"r+");
        fp=fopen(result,"w");
        if(ft==0){
                printf("file not there");
                return 0;
        }
        comment(ft);
        fs=fopen("temp.c","r");
        rewind(fs);
        //fgets(temp,100,fs);
        sll *hptr;
        hptr=NULL;
        prepro(fs,fp,&hptr);


        repmacro(fs,fp,hptr);
        while((ch=fgetc(fs))!=EOF)
        {
                if(ch=='\n')
                        l++;
                b++;
        }
        fseek(fs,-b,SEEK_CUR);
        char **s;
        s=malloc(sizeof(char*)*l);
        for(i=0;i<l;i++)
                s[i]=malloc(sizeof(char)*100);
        for(i=0;i<l;i++){
                fgets(s[i],100,fs);
        }
        remove("temp.c");
}

