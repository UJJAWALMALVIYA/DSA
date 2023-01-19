#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
struct queue{
    struct node *front;
    struct node *rear;
};
int main()
{
    struct queue p;
    int choice;
    while (1)
    {
        printf("1.enqueue\n");
        printf("2.dequeue\n");
        printf("3.exit\n");
        printf("enter the choice");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue(&p,5);
            enqueue(&p,7);
            enqueue(&p,9);
            enqueue(&p,2);
            break;\
        case 2:
            dequeue(&p);
            break;
        case 3:
            printf("exit\n");
            break;
        default:
            printf("wrong choice\n");
            break;
        }
    }
    
}
void enqueue(struct queue *q,int item)
{
    q->front=q->rear=NULL;
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if (temp==NULL)
    {
        printf("QUEUE IS OVERFLOW\n");
    }
    else{
        temp->data=item;
        temp->link=NULL;
        printf("QUEUE IS %d\n",temp->data);
    }
    if (q->front==NULL)
    {
        q->rear=q->front=temp;
        return ;
    }
    q->rear->link=temp;
    q->rear=q->rear->link;
    
    
}
void dequeue(struct queue *q)
{
    struct node *temp;
    int item;
    if (q->front==NULL)
    {
        printf("QUEUE IS EMPTY\n");
        return NULL;
    }
    else{
        item=q->front->data;
        printf("DELETED ITEM IS %d\n",item);
        temp=q->front;
        q->front=q->front->link;
        free(temp);
    }
    
}