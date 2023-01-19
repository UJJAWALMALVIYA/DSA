#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int arr[MAX];
int front=-1,rear=-1;
int main()
{
    enqueue(5);
    enqueue(6);
    enqueue(4);
    enqueue(2);
    display();

    dequeue();
    display();
}
void enqueue(int data)
{
    if (rear==MAX-1)
    {
        printf("YOUR QUEUE IS OVERFLOW\n");
    }
    else if (front==-1 && rear ==-1)
    {
        front=rear=0;
        arr[rear]=data;
    }
    else{
        rear=(rear+1)%MAX;
        arr[rear]=data;
    }
}
void dequeue()
{
    if (front==-1&&rear==-1)
    {
        printf("YOUR QUEUE IS UNDERFLOW\n");
    }
    else
    {
        printf("DELETED ITEM IS %d\n",arr[front]);
        front=(front+1)%MAX;
    }
}
void display()
{
    if (front==-1 && rear ==-1)
    {
        printf("YOUR QUEUE IS EMPTY\n");
    }
    else{
        for (int i = front; i < rear+1; i++)
        {
            printf("YOUR QUEUE IS %d\n",arr[i]);
        }
        
    }
    
}