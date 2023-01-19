#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *prev;
    struct node *next;
};
int main()
{
    struct node *p=NULL;
    insert(&p,2);
	insert(&p,44);
	insert(&p,25);
	insert(&p,14);
	insert(&p,5);
	insert(&p,65);
	insert(&p,55);
    printf("DLL BEFORE INSERTION\n");
    display(p);

    atbeg(&p,100);
    atbeg(&p,120);
    printf("DLL INSERTION AT BEGINNNING\n");
    display(p);

    atend(&p,150);
    printf("DLL INSERTION AT END\n");
    display(p);

    atindex(&p,5,160);
    printf("INSERTION AT INNDEX\n");
    display(p);

}
void insert(struct node **head,int item)
{
    struct node *temp,*r;
    temp=(struct node*)malloc(sizeof(struct  node));
    temp->data=item;
    temp->next=NULL;
    temp->prev=NULL;
    if (*head==NULL)
    {
        *head=r=temp;
    }
    else{
        r->next=temp;
        temp->prev=r;
        r=temp;
    }
    
}
void atbeg(struct node **head,int item)
{
    struct node *newnode;
    struct node *temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=*head;
    temp->prev=newnode;
    newnode->prev=*head;
    *head=newnode;

}
void atend(struct node **head,int item)
{
    struct node *newnode;
    struct node *temp=*head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=NULL;
    newnode->prev=temp;
    temp->next=newnode;
    
}
void atindex(struct node **head,int index,int item)
{
    int i;
    struct node *newnode;
    struct node *temp=*head;
    for(i=0;i<index;i++)
    {
        temp=temp->next;
    }
    struct node *ptr=temp->next;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=item;
    newnode->next=ptr;
    temp->next=newnode;
    newnode->prev=temp;
}
void display(struct node *head)
{
    struct node *ptr=head;
    while (ptr !=NULL)
    {
        printf("ITEM ARE %d\n",ptr->data);
        ptr=ptr->next;
    }
    
}