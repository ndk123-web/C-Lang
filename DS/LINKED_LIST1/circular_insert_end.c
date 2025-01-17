#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *link;
};

  
  void traverse(struct node *head)
  {
    struct node *ptr;
    ptr=head;
    do{
        printf("Element : %d\n",ptr->data);
        ptr=ptr->link;
    }while(ptr!=head);
    
  }

  struct node *insertend(struct node *head,int data)
  {
    struct node *newnode=(struct node *) malloc(sizeof(struct node ));
    struct node *p=head;
    newnode->data=data;
    while(p->link!=head)
    {
        p=p->link;
    }
p->link=newnode;
newnode->link=head;
return head;
  }
  

int main()
{
    struct node *head,*second,*third,*fourth;
    head=(struct node * ) malloc(sizeof(struct node ));
    second=(struct node * ) malloc(sizeof(struct node ));
    third=(struct node * ) malloc(sizeof(struct node ));
    fourth=(struct node * ) malloc(sizeof(struct node ));
    
     head->data=10;
     head->link=second;

     second->data=20;
     second->link=third;

     third->data=30;
     third->link=fourth;

     fourth->data=40;
     fourth->link=head;

     traverse(head);
     head=insertend(head,50);
     printf("Newly Inserted \n");
     traverse(head);
     return 0;

 }
