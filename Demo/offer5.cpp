//
// Created by 廖洲洲 on 2020/10/1.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char* replaceSpace(char* s){
    if(!s)
        return NULL;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]==' ')
            len+=2;
    }
    char *result;
    result=(char *)malloc((len+1)*sizeof(char));
    int j=0;
    for(int i=0;i<len;i++){
        if(s[i]==' '){
            result[j++]='%';
            result[j++]='2';
            result[j++]='0';
        }else{
            result[j++]=s[i];
        }
    }
    result[j]='\0';
    return result;
}
int main(){
    char s[100]="We are happy.";
    char *tmp=replaceSpace(s);
    printf("%s\n",tmp);
}