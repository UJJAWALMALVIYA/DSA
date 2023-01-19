#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int arr[MAX];
int front =-1,rear=-1;
int main()
{
    enqueue(5);
    enqueue(7);
    enqueue(8);
    enqueue(4);
    enqueue(2);
    enqueue(3);
    display();

    dequeue();
    display();
}

void enqueue(int data)
{
    if (rear==MAX-1){
        printf("YOUR QUEUE IS OVERFLOW \n");
    }
    else if (front==-1 && rear==-1)
    {
        front=rear=0;
        arr[rear]=data;   
    }
    else
    {
        rear++;
        arr[rear]=data;
    }
}

void dequeue()
{
    if (front==-1&& rear==-1)
    {
        printf("YOUR QUEUE IS UNDER FLOW\n");
    }
    else{
        printf("DELETED ITEM IS %d\n",arr[front]);
        front++;
    }
}
void display()
{
    if (front==-1 && rear==-1)
    {
        printf("YOUR QUEUE IS EMPTY\n");
    }
    else{
        for (int i =front ; i<rear+1; i++)
        {
            printf("YOUR QUEUE IS %d\n",arr[i]);
        }
        
    }
}