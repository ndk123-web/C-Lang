#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

typedef struct {
    node *start;
}LL;

void insertbegin(LL *l,int data)
{
    node *new;
    new=(node*)malloc(sizeof(node));
        new->data=data;
        new->next=l->start;
        l->start=new;
}

void display(LL *l)
{
    node *p;
    p=l->start;

    while(p!=NULL)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}

void insertend(LL *l,int data)
{
    node *new;
    new=(node*)malloc(sizeof(node));
    node *p;
    p=l->start;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    new->data=data;
    p->next=new;
    new->next=NULL;

}

void insertpos(LL *l,int data,int pos,int c)
{
   node *new;
   new=(node *)malloc(sizeof(node));
   node *p,*q;
   p=l->start;
   q=NULL;
   printf("Count :%d\n",c);

   if(pos==1 || l->start==NULL){
   new->data=data;
   new->next=l->start;
   l->start=new;
   return;
   }

   if(pos==c){
   while(p->next!=NULL)
   {
       p=p->next;
   }
   p->next=new;
   new->data=data;
   new->next=NULL;
   return;
}

   if(pos>c){
   printf("Invalid Position");
   return;
   }

   for(int i=0;i<pos-1;i++)
   {
    q=p;
    p=p->next;
   }
   new->data=data;
   q->next=new;
   new->next=p;
}

void deletebegin(LL *l)
{
    node *p,*q;
    p=l->start; 
    if(l->start==NULL)
    {
        printf("Linked list Empty");
        return ;
    }
p = l->start;
q = l->start->next;
l->start = q;
free(p);
}

void deleteend(LL *l)
{
    node *p,*q;
    p=l->start;
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    free(p);
    q->next=NULL;
}

void deletepos(LL *l,int pos,int c)
{
    node *p;
    p=l->start;

    if(l->start==NULL)
    {
        printf("Linked List Empty");
        return;
    }

    if(pos==1)
    {
        node *p,*q;
        p = l->start;
        q = l->start->next;
        l->start = q;
        free(p);
        return;
    }

    if(pos==c)
    {
    node *p,*q;
    q=NULL;
    p=l->start;
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
    }
    free(p);
    q->next=NULL;
    return;
    }

    if(pos>c)
    {
        printf("Invalid position");
        return;
    }

    if(pos<c)
    {
        node *p,*q;
        p=l->start;
        q=NULL;
    for(int i=0;i<pos-1;i++)
    {
        q=p;
        p=p->next;
    }
    q->next=p->next;
    free(p);
    }
}

void search(LL *l,int data)
{
    node *p,*q;
    p=l->start;
    q=NULL;

    while(p!=NULL)
    {
        if(p->data==data){
        printf("FOUND !!");
        return;
        }
        p=p->next;
    }
    printf("Not found !!");
}

void sort(LL *l)
{
    node *p,*q;
    int t;
    p=l->start;
    for(p=l->start;p->next!=NULL;p=p->next)
    {
        for(q=l->start;q->next!=NULL;q=q->next)
        {
            if(q->data > q->next->data)
            {
            t=q->data;
            q->data=q->next->data;
            q->next->data=t;
            }
        }
    }
}

void nodes(LL *l,int c)
{
    printf("Total Nodes: %d",c);
}

void reverse(LL *l)
{
     node *current,*prev,*next;
     current=l->start;
     prev=NULL;

     while(current!=NULL)
     {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
     }
     l->start=prev;
}

void main()
{
    LL l;
    l.start=NULL;
    int pos,ch,data,c=0;
    while(1)
    {
        printf("\n1.Insert at beginning\n2.Display\n3.Exit\n4.Insert at end\n5.Insert at Position\n6.Delete at begin\n7.Delete at End\n8.Delete at Position\n9.Search Data\n10.Sort Data\n11.Total Nodes\n12.Reverse node\n");
        printf("Enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter data");
                    scanf("%d",&data);
                    c++;
                    insertbegin(&l,data);
                    break;

            case 2: display(&l);
                    break;

            case 3: return ;
                    break;

            case 4: printf("Enter data");
                    scanf("%d",&data);
                    insertend(&l,data);
                    c++;
                    break;

            case 5: printf("Enter data");
                    scanf("%d",&data);
                    printf("Enter position");
                    scanf("%d",&pos);
                    c++;
                    insertpos(&l,data,pos,c);
                    break;

            case 6: 
                    deletebegin(&l);
                    c--;
                    break;

            case 7: 
                    deleteend(&l);
                    c--;
                    break;

            case 8: 
                    printf("Enter position");
                    scanf("%d",&pos);
                    deletepos(&l,pos,c);
                    c--;
                    break;

            case 9: printf("Enter data to search");
                    scanf("%d",&data);
                    search(&l,data);
                    break;

            case 10: sort(&l);
                     break;

            case 11: nodes(&l,c);
                    break;

            case 12: reverse(&l);
                    break;


            default : printf("Invalid choice");
                      break;

        }
    }
}