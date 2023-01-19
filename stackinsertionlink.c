#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *s;
    push(&s, 60);
    push(&s, 61);
    push(&s, 62);
    push(&s, 65);
    push(&s, 4);

    int i=pop(&s);
    if (i != NULL)
    {
        printf("YOUR POPPED ITEM IS %d\n");
    }
    else{
        printf("NO USE\n");
    }
    

    return 0;
}
void push(struct node **top,int item)
{
    struct node *temp;
    temp=(struct  node*)malloc(sizeof(struct node));
    if (isFull(temp))
    {
        printf("YOUR STACK IS OVERFLOW\n");        
    }
    else{

        temp->data=item;
        temp->next=*top;
        *top=temp;
        printf("YOUR ITEMS IS: %d\n",item);
    }
    
}
int pop(struct node *top)
{
    struct node *temp=top;
    if (isEmpty(top))
    {
        printf("STACK IS UNDERFLOW\n");
    }
    else{
        int value;
        value=temp->data;
        top=top->next;
        free(temp);
        return value;
    }
    
}
int isFull(struct node *top)
{
    if (top==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}
int isEmpty(struct node *top)
{
    if (top==NULL)
    {
        return 1;
    }
    else{
        return 0;
    }
    
}