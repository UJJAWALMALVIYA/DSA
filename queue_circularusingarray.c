#include<stdio.h>
#define MAX 10

int front=-1;
int rear=-1;
int arr[MAX];
int main()
{
    enqueue(25);
    enqueue(2);
    enqueue(75);
    enqueue(7);
    enqueue(5);
    printf("DISPLAYED QUEUE BEFORE DELETION\n");
    display();

    dequeue();
    printf("DISPLAYED QUEUE AFTER DELETION\n");
    display();
    
}
void enqueue(int item)
{
    if (rear==MAX-1)
    {
        printf("YOUR QUEUE IS OVERFLOW\n");
    }
    else{
        rear=(rear+1)%MAX;
        arr[rear]=item;
        // printf("YOUR ITEM IS %d\n",item);
    }
    
}
int dequeue()
{
    int val=-1;
    if (front==rear==-1)
    {
        printf("YOUR QUEUE IS UNDEERFLOW\n");
    }
    else{
        front=(front+1)%MAX;
        val=arr[front];
        printf("YOUR DEQUEUE ITEM IS %d\n",val);
        return val;    
    }
    
}
void display()
{
    for (int i =front+1 ;i < rear+1; i++)
    {
        printf("YOUR ITEM ARE %d\n",arr[i]);
    }
    
}