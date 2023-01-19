#include<stdio.h>
#include<stdlib.h>
#define MAX 20

struct node{
    int front;
    int rear;
    int arr[MAX];

};int front=-1;
int rear=-1;
int main()
{
    int i=0;
    struct node *s;
    enqueue(&s,5);
    enqueue(&s,6);
    enqueue(&s,2);
    enqueue(&s,55);
    enqueue(&s,59);
    enqueue(&s,21);
    enqueue(&s,7);

    i=dequeue(&s);
    i=dequeue(&s);
    i=dequeue(&s);

}
void enqueue(struct node *s,int item)
{
    if (s->rear==MAX-1)
    {
        printf("YOUR QUEUE IS OVERFLOW\n");
    }
    else{
        s->rear++;
        s->arr[s->rear]=item;
        printf("YOUR ITEMS IS : %d\n",item);

    }
    
}
int dequeue(struct node *s)
{
    int val=-1;
    if (s->front == s->rear)
    {
        printf("YOUR QUEUE IS UNDERFLOW\n");
    }
    else{
        s->front++;
        val=s->arr[s->front];
        printf("YOUR DEQUEUE ITEM IS : %d\n",val);
    }
    return val; 
}