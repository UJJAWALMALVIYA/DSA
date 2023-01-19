#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    struct node *second=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));
    
    head->data=25;
    head->next=second;
    second->data=5;
    second->next=third;
    third->data=2;
    third->next=NULL;
    printf("LINKED LIST BEFORE DELETION\n");
    linktraversal(head);
    // printf("LINKED LIST AFTER DELETION FIRST ITEM\n");
    // head = deletefirst(head);
    // linktraversal(head);

    head=deleteatindex(head,0);
    printf("LINKED LIST AFTER DELETION INDEX ITEM\n");
    linktraversal(head);
    // head=deleteend(head);
    // printf("LINKED LIST SFTER DELETION OF END NODE \n");
    // linktraversal(head);
    // return 0;
}
int deletefirst(struct node *head)
{
    struct node *ptr;
    ptr=head;
    head=head->next;
    free(ptr);
    return head;

}
void linktraversal(struct node *head)
{
    while (head != NULL)
    {
        printf("YOUR ITEM IS : %d \n",head->data);
        head=head->next;
    }
    
}
int deleteatindex(struct node *head,int index)
{
    int i;
    struct node *ptr=head;
    for(i=0;i<index-1;i++)
    {
        ptr=ptr->next;
    }
    struct node * temp=ptr->next;
    ptr->next=temp->next;
    free(temp);
    return head;

}
int deleteend(struct node *head)
{
    struct node *ptr=head;
    struct node *q=head->next;
    while (q->next != NULL)
    {
        q=q->next;
        ptr=ptr->next;
    }
    ptr->next=NULL;
    free(q);
    return head;
}
