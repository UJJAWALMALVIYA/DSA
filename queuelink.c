#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

int main()
{
    struct node *s;
    printf("QUEUE LINKED LIST ARE :");
    enqueue(&s,5);
    enqueue(&s,89);
    enqueue(&s,7);
    enqueue(&s,8);
    enqueue(&s,1);
    display(front);
    dequeue(&s);
    printf("LINKED LIST OF QUEUE AFTER DELETED A ITEM\n");
    display(front);
}
void enqueue(struct node **s,int item)
{
    struct node *temp=*s;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=NULL;
    *s=temp;
    if (temp==NULL)
    {
        printf("QUEUE IS OVERFLOW\n");
    }
    else{
        if (front==NULL)
        {
            front=rear=temp;
        }
        else{
            rear->next=temp;
            rear=temp;
        }
        
    }
}
int dequeue(struct node *s)
{
    int val=-1;
    struct node *ptr=front;
    if (rear==front)
    {
        printf("YOUR QUEUE IS UNDEFLOW\n");
    }
    else{
        front=front->next;
        val=ptr->data;
        printf("\n\nYOUR DEQUEUE ITEM IS %d\n\n",val);
        free(ptr);
        return val;
    }
    
}
void display(struct node *q)
{
    while (q != NULL)
    {
        printf("YOUR QUEUE ITEM IS : %d\n",q->data);
        q=q->next;
    }
    
}