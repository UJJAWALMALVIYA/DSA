#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct node
{
    char data;
    struct node *left;
    struct node *right;
};
int top=-1;
int arr[MAX];
void push(int item)
{
    if (top==MAX-1)
    {
        printf("YOUR STACK IS FULL\n");
    }
    else
    {
        top++;
        arr[top]=item;
    }
}
int pop()
{
    int val=-1;
    if (top==-1)
    {
        printf("YOUR STACK IS EMPTY\n");
    }
    else{
        val=arr[top];
        top--;
        return val;
    }
    
}

void insert(struct node *root)
{
    if (root != NULL)
    {
        if (root->right != NULL)
        {
            push(root->data);
        }
        else{
            return 0;
        }
        
        
    }
    
}
