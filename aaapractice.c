#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *p=NULL;
    create(&p,4);
    create(&p,5);
    create(&p,2);
    create(&p,1);
    create(&p,45);
    create(&p,8);
    // display(p);
    inbeg(&p,78);
    // display(p);
    atindex(&p,55,4);
    // display(p);
    atend(&p,500);
    display(p);
}
void create(struct node **head,int item)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if (*head==NULL)
    {
        temp->data=item;
        temp->next=NULL;
        *head=temp;
    }
    else{
        temp=*head;
        while (temp->next != NULL)
        {
            temp=temp->next;
        }
        struct node *r;
        r=(struct node *)malloc(sizeof(struct node));
        r->data=item;
        r->next=NULL;
        temp->next=r;
    }
}
void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d\n",head->data);
        head=head->next;
    }
    
}
void inbeg(struct node **head,int item)
{
    struct node *temp;
    struct node *ptr=*head;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=ptr;
    *head=temp;
}
void atindex(struct node **head,int item,int index)
{
    int i;
    struct node *ptr=*head;
    struct node *temp;
    for(i=0;i<index-1;i++)
	{
		ptr=ptr->next;
	}
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=ptr->next;
    ptr->next=temp;
}
void atend(struct node **head,int item)
{
    struct node *ptr=*head;
    struct node *temp;
    while (ptr->next != NULL)
    {
        ptr=ptr->next;
    }
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=NULL;
    ptr->next=temp;
}