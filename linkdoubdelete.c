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

    // p=inbeg(p);
    // display(p);
    // p=inend(p);
    // display(p);
    p=atindex(p,2);
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
int inbeg(struct node *head)
{
    struct node *temp=head;
    struct node *ptr=head->next;
    head=head->next;
    ptr->prev=head;
    free(temp);
    return head;
}
int inend(struct node *head)
{
    struct node *temp=head;
    struct node *ptr=head->next;
    while (ptr->next != NULL)
    {
        temp=temp->next;
        ptr=ptr->next;
    }
    temp->next=NULL;
    free(ptr);
    return head;
    
}
int atindex(struct node *head,int index)
{
    int i;
    struct node *temp=head;
    for ( i = 0; i < index; i++)
    {
        temp=temp->next;
    }
    struct node *ptr=temp->next;
    temp->next=ptr->next;
    ptr->prev=temp;
    free(ptr);
    return head;
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