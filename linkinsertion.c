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
	display(p);

	inbeg(&p,1);
	display(p);

	inatindex(&p,2,9);
	display(p);

	atend(&p,33);
	display(p);
}
void insert(struct node **q,int item)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	if (*q==NULL)
	{
		temp->data=item;
		temp->next=NULL;
		*q=temp;
	}
	else{
		temp=*q;
		while (temp->next!= NULL)
		{
			temp=temp->next;
		}
		struct node *r;
		r=(struct node*)malloc(sizeof(struct node));
		r->data=item;
		temp->next=r->next=NULL;
	}
	
}
void inbeg(struct node **q,int item )
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=*q;
	*q=temp;
}
void atend(struct node **q,int item)
{
	struct node *temp,*ptr;
	ptr=*q;
	while (ptr->next != NULL)
	{
		ptr=ptr->next;
	}
	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=NULL;
	ptr->next=temp;
}
void inatindex(struct node **q,int index,int item)
{
	int i;
	struct  node *ptr,*temp;
	ptr=*q;
	for(i=0;i<index-1;i++)
	{
		ptr=ptr->next;
	}
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=ptr->next;
	ptr->next=temp;
	
}
void display(struct node *q)
{
	while (q != NULL)
	{
		printf("item is %d\n",q->data);
		q=q->next;
	}
	
}

