#include<stdio.h>
#include<stdlib.h>
void append();
struct node {
    int data;
    struct node *link;
};
struct node *root;

void main()
{
    append();
}

void append()
{
    struct node *temp;
    temp=(struct node*) malloc(sizeof(struct node));
    printf("Enter Node data");
    scanf("%d",&temp->data);

    if(root==NULL){
      root=temp;
    }
    else{
        struct node *p;
        p=root;

        while(p->link!=NULL)
        {
            p=p->link;
        }
        p->link=temp;
    }
    
    
}
