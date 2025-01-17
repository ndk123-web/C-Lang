#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

 void traverse(struct node *a)
 {
     struct node *p=a;
     while(p!=NULL)
     {
         printf("Element : %d\n" , p->data);
         p=p->next;
     }
 }
 
 void reverse(struct node *d)
 {
     struct node *q=d;
     while(q!=NULL)
     {
         printf("Element : %d\n",q->data);
         q=q->prev;
     }
 }

 int main()
 {
     struct node *a,*b,*c,*d;
     a=(struct node *) malloc(sizeof(struct node ));   
     b=(struct node *) malloc(sizeof(struct node ));
     c=(struct node *) malloc(sizeof(struct node ));
     d=(struct node *) malloc(sizeof(struct node ));
           
    a->data=10;
    a->prev=NULL;
    a->next=b;
    
    b->data=20;
    b->prev=a;
    b->next=c;
    
    c->data=30;
    c->prev=b;
    c->next=d;
    
    d->data=40;
    d->prev=c;
    d->next=NULL;
    printf("Linear Circle link list \n");
    traverse(a);
    printf("Reverse circle link list \n");
    reverse(d);
    return 0;
}