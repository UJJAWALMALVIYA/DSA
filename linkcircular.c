#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
int main()
{
	struct node *p =NULL;
	insert(&p,2);
	insert(&p,44);
	insert(&p,25);
	insert(&p,14);
	printf("CIRCULAR LINKED LIST BEFORE INSERTION\n");
	display(p);

	inbeg(&p,5446);
	printf("CIRCULAR LINKED LIST INSERTION AT BEGINNING \n");
	display(p);

	inatindex(&p,3,9);
	printf("CIRCULAR LINKED LIST INSERTION AT SPECIFIC INDEX\n");
	display(p);

	atend(&p,33);
	printf("CIRCULAR LINKED LIST INSERTION AT END\n");
	display(p);
}
void insert(struct node **head,int item)
{
	struct node *temp,*ptr,*r;
	temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
	temp->next=NULL;
	if (*head==NULL)
	{
		*head=ptr=temp;
	}
	else{
		while (ptr->next!= *head)
		{
			ptr=ptr->next;
		}
		
		r=(struct node*)malloc(sizeof(struct node));
		r->data=item;
		ptr->next=r;
        ptr=r;
        
	}
    ptr->next=*head;
}

void display(struct node *head)
{
    struct node *ptr=head;
	do
    {
       printf("item is %d\n",head->data);
	   head=head->next;
    } while (ptr != head);
	
}
void inbeg(struct node **head,int item)
{
    struct node *temp;
    struct node *ptr=*head;
	do
	{
		ptr=ptr->next;
	} while (ptr->next != *head);
	
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=*head;
    ptr->next=temp;
    *head=temp;   
}
void atend(struct node **head,int item)
{
	struct node *temp;
	struct node *ptr=*head;
	do
	{
		ptr=ptr->next;
	} while (ptr->next != *head);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=*head;
	ptr->next=temp;
}
void inatindex(struct node **head,int index,int item)
{
	int i;
	struct node *temp;
	struct node *ptr=*head;
	for(i=0;i<index-1;i++)
	{
		ptr=ptr->next;
	}
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=ptr->next;
	ptr->next=temp; 

}