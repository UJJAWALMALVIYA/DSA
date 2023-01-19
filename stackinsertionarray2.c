#include<stdio.h>
#include<stdlib.h>
#define MAX 20

int arr[MAX];
int top=-1;
int main()
{
    int i;
    push(4);
    push(6);
    push(8);
    push(9);

    pop();


}
void push(int item)
{
    if (top==MAX-1)
    {
        printf("STACK IS OVERFLOW\n");
    }
    else{
        top++;
        arr[top]=item;
        printf("YOUR ITEM ARE %d\n",item);
    }
    
}
int pop()
{
    if (top==-1)
    {
        printf("YOUR STCAK IS UNDERFLOW\n");
    }
    else{
        int val;
        val=arr[top];
        printf("YOUR POPPED VALUE IS %d\n",val);
        top++;
        return val;
    }
    
}
