#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void copy(char **source,char **dest){
    strcpy(*dest,*source);
}

int main()
{
    char *c="ndk";
    char *des=(char*) malloc(sizeof(char)*(strlen(c)+1));
    copy(&c,&des);
    printf("\n%s\n",des);
    return 0;
}