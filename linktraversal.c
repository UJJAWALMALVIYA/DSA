#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void linktraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("element : %d\n",ptr->data);
        ptr=ptr->next;
    }
    
}
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));

    head->data=6;
    head->next=second;

    second->data=66;
    second->next=third;

    third->data=77;
    third->next=NULL;

    linktraversal(head);
    return 0;
}
