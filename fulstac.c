#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top=-1;
int arr[MAX];
struct node
{
    int data;
};
int main()
{
    int choice;
    for(int i=top;i<MAX;i++)
    {
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.exit\n");
        printf("enter the choice\n",choice);
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push(2);
            push(1);
            push(3);
            push(4);
            push(9);
            // printf("enter the to be pushed\n",push);
            // scanf("%d",&push);
            break;
        case 2:
            pop();
            if (top != -1)
            {
                printf("element popped is %d\n",arr[MAX]);
            }
            break;

        case 3:
            printf("exit\n");
            break;

        default:
            printf("YOU TOOKED WRONG CHOICE\n");
            break;
        }
    }
    
    return 0;
    
}
void push(int data)
{
    if (top==(MAX-1))
    {
        printf("YOUR STACK IS OVER FLOW\n");
    }
    else{
        top=top+1;
        arr[MAX]=data;
        printf("pushed value are %d\n",arr[MAX]);
    }
    
}
int pop()
{
    int value;
    if (top==-1)
    {
        printf("YOUR STACK IS UNDER FLOW\n");
    }
    else{
        value=arr[MAX];
        top=top-1;
        return value;
    }
    
}
