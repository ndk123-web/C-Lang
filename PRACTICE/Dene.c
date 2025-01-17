#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
    char id[50];
    char name[50];
};

void display(struct Student *s,int c)
{
    for(int i=0;i<c;i++){
        printf("%s\n",s[i].id);
    }
}

void check(struct Student s[],char *cid,int c)
{
    for(int i=0;i<c;i++){
    {
        if(strcmp(s[i].id,cid)==0)
        printf("Successfully Exit\n");
        else
        printf("Not Found\n");
    }   
    }
}

int main()
{
    int ch,i;
    struct Student s[100];
    int c=0;
    char cid[50];
    while(1)
    {
        printf("1.Entry\n2.Exit\n3.Display\n4.Return\n");
        printf("Enter your choice");
        scanf("%d",&ch);

        switch(ch){
            case 1: printf("Enter Name");   
                    scanf("%s",&s[c].name);
                    printf("Enter Id");
                    scanf("%s",&s[c].id);
                    c++;
                     break;

            case 2: printf("Enter Id ");
                    scanf("%s",&cid);
                    check(s,cid,c);
                    break;

            case 3: printf("All Details : ");
                    display(s,c);
                    break;

            case 4: return 0;
                    break;

            default: printf("Invalid Option");
                     break;

        }
    }
}