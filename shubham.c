#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertatbeg()
{
    struct node *head, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
}
void main()
{
    int choice;
    struct node *head, *newnode, *temp;
    head = NULL;
    while (1)
    {
        if (head == NULL)
        {
           newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d", &newnode->data);
        newnode->next = NULL;
        }
        else
        {
            newnode = head;
            while (newnode->next != NULL)
            {
                newnode = newnode->next;
            }

            temp = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data:");
            scanf("%d", &temp->data);
            temp->next = NULL;
            newnode->next=temp;
        }
        printf("Enter your choice(0,1)");
        scanf("%d", &choice);
    }
    insertatbeg();
    temp = head;
    while (temp!= NULL)
    {
        printf("%d\t", temp->data);
        temp =temp->next;
    }
    exit(1);
}