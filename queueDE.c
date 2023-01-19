#include<stdio.h>
#define MAX 50

int front=-1;
int rear=-1;
int arr[MAX];
int main()
{
    int i;
    enqueueR(6);
    enqueueR(5);
    enqueueR(28);
    enqueueR(-9);
    enqueueR(10);
    enqueueR(17);
    enqueueR(8);
    enqueueR(13);
    enqueueR(14);
    enqueueR(25);
    
    display();

    i=dequeueF();
    i=dequeueF();
    i=dequeueF();
    i=dequeueF();

    enqueueF(16);
    enqueueF(7);
    enqueueF(66);

    display();

    i=dequeueR();
    i=dequeueR();


    display();
}
void enqueueR(int item)
{
    if (rear==MAX-1)
    {
        printf("YOUR QUEUE IS OVERFLOW\n");
    }
    else{
        rear++;
        arr[rear]=item;
        // printf("YOUR ITEMS ARE : %d\n",item);
    }
    
}
void enqueueF(int item)
{
    if (front==-1)
    {
        printf("YOU ENTERED ITEM LAST IN QUEUE\n");
        return 0;
    }
    else{
        arr[front]=item;
        front--;
        // printf("YOUR ITEMS ARE : %d\n",item);
    }
    
}
int dequeueF()
{
    int val=-1;
    if (front==rear)
    {
        printf("YOUR QUEUE IS UNDEFLOW\n");
    }
    else{
        front++;
        val=arr[front];
        printf("YOUR DEQUEUE ITEM IS %d\n",val);
    }
    return val;
    
}
int dequeueR()
{
    int val=-1;
    if (rear==-1)
    {
        printf("YOUR QUEUE IS UNDEFLOW\n");
    }
    else{
        val=arr[rear];
        printf("YOUR DEQUEUE ITEM FROM LAST OF QUEUE: %d\n",val);
        rear--;
    }
    return val;
}

void display(){
    for (int i = front+1; i < rear+1; i++)
    {
        printf("YOUR ITEM ARE %d\n",arr[i]);
    }
    
}