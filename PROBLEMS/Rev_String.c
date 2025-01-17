#include<stdio.h>
#include<string.h>

char *reversestring(char *c,int st,int end){
    if(st>=end){
        return c;
    }else{
        char t=c[st];
        c[st]=c[end];
        c[end]=t;
        reversestring(c,st+1,end-1);
    }
}

int main()
{
    char c[]="Hello";
    int len=strlen(c);
    char *rev=reversestring(c,0,len-1);
    printf("Reverse String is %s ",rev);
}