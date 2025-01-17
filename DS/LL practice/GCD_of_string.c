#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(int a,int b);
int canrepeat(char *str,char *sub);
char* gcdofstring(char *s1,char *s2);

int gcd(int a,int b){
    int z=a%b;
    if(z==0) return b;
    else return gcd(b,z);
}

int canrepeat(char *str,char *sub){
    int len=strlen(str);
    int sublen=strlen(sub);
    if(len%sublen!=0) return 0;

    for(int i=0;i<len;i++){
        if(str[i]!=sub[i%sublen]) return 0;
    }
    return 1;
}

char* gcdofstring(char *s1,char *s2){
    int len1=strlen(s1);
    int len2=strlen(s2);
    int gcdlen=gcd(len1,len2);
    
    char *gcdstr=(char*) malloc((gcdlen+1)*sizeof(char));
    if(gcdstr==NULL){
        fprintf(stderr,"Memory Not Allocated");
        return "";
    }

    strncpy(gcdstr,s1,gcdlen);
    gcdstr[gcdlen]='\0';

    if(canrepeat(s1,gcdstr) && canrepeat(s2,gcdstr) ){
        return gcdstr;
    }else{
        return "";
    }
}

int main()
{
    char a[]="ABCABC";
    char b[]="ABC";

    printf("%s",gcdofstring(a,b));
    return 0;
}