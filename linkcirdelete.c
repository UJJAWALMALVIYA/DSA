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
	insert(&p,5);
	insert(&p,65);
	insert(&p,55);
	printf("CIRCULAR LINKED LIST BEFORE INSERTION\n");
	display(p);

    p = inbeg(p);
	printf("CIRCULAR LINKED LIST AFTER THE DELETION OF FIRST NODE\n");
    display(p);

	 p = atend(p);
	printf("CIRCULAR LINKED LIST AFTER THE DELETION OF LAST NODE\n");
    display(p);

	
	p = atindex(p,4);
	printf("CIRCULAR LINKED LIST AFTER THE DELETION OF ANY INDEX \n");
    display(p);

}
int inbeg(struct node *head)
{
    struct node *ptr=head;
    do
    {
        ptr=ptr->next;
    } while (ptr->next != head);
    
    head=head->next;
	ptr->next=head;  
	return head;
}
int atend(struct node *head)
{
	struct node *ptr=head;
	struct node *q=head->next;
	do
	{
		q=q->next;
		ptr=ptr->next;
	} while (q->next!=head);
	ptr->next=head;
	free(q);
	return head;
	
}
int atindex(struct node *head,int index)
{
	struct node *ptr=head;
	int i;
	for(i=0;i<index-1;i++)
	{
		ptr=ptr->next;
	}
	struct node *q=ptr->next;
	ptr->next=q->next;
	free(q);
	return head;
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