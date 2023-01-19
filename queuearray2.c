#include<stdio.h>
#define MAX 20

int arr[MAX];
int front=-1;
int rear=-1;

int main()
{
    int i;
    enqueue(5);
    enqueue(4);
    enqueue(99);
    enqueue(8);

    i=dequeue();
    
}
void enqueue(int item)
{
    if (rear==MAX-1)
    {
        printf("YOUR QUEUE IS OVERFLOW\n");
    }
    else{
        rear++;
        arr[rear]=item;
        printf("YOUR ITEMS ARE :%d\n",item);
    }
    
}
int dequeue()
{
    int val = -1;
    if (front==rear)
    {
        printf("YOUR QUEUE IS UNDERFLOW\n");
    }
    else{
        front++;
        val=arr[front];
        printf("YOUR DEQUEUE ITEM IS %d\n",val);
    }
    return val;
    
}