#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
int main()
{
    struct node *s=NULL;
        int choice;
    while(1)
    {
        printf("1.PUSH\n");
        printf("2.POP\n");
        printf("3.exit\n");
        printf("enter the choice\n",choice);
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push(&s,5);
            push(&s,6);
            push(&s,4);
            push(&s,7);
            // printf("enter the to be pushed\n",push);
            // scanf("%d",&push);
            break;
        case 2:
            pop(&s);
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

void push(struct node **top , int item)
{
    struct node *temp;
    temp=(struct node *)malloc (sizeof (struct node));
    if (temp==NULL)
    {
        printf("STACK IS FULL\n");
    }
    else{
        temp->data=item;
        temp->link=*top;
        *top=temp;
    }
    printf("PUSHED ITEM ARE %d\n",temp->data);
    
}
int pop(struct node **top)
{
    struct node *temp;
    int item;
    if (*top==NULL)
    {
        printf("STACK IS UNDER FLOW\n");
        return ;
    }
    else{
        temp=*top;
        item=temp->data;
        *top=temp->link;
        printf("popped value is %d\n",temp->data);

        free(temp);
        return item;
    
    }
    
}

