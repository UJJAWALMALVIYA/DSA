#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    struct node *p;
    p=NULL;
    int choice,n;
    printf("enter the term of linklist");
    scanf("%d",&n);
    while (n)
    {
        printf("\n1.create\n");
        printf("2 insertbeg\n");
        printf("3.exit\n");
        printf("enter the choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            create(&p);
            break;
        case 2:
            insertbeg(&p);
            break;
        case 3:
            printf("EXIT\n");
            display(p);
            break;
        
        default:
            printf("you took a wrong selection\n");
            break;
        }

    }
    return 0;
    
}
void create(struct node **q)
{
    struct node *newnode,*r;
    
    if (*q==NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    *q=newnode;
    }
    else{
        newnode=*q;
        while (newnode->next!=NULL)
        {
            newnode=newnode->next;
        }

        r=(struct node*)malloc(sizeof(struct node));
         printf("enter the data : ");
        scanf("%d",&r->data);
        r->next=NULL;
        newnode->next=r;
        
    }
    
}
void insertbeg(struct node **q)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the data : ");
    scanf("%d",&newnode->data);
    newnode->next=*q;
    *q=newnode;
}
void display(struct node *q)
{
    while (q!=NULL)
    {
        printf("%d\t",q->data);
        q=q->next;
    }
    
}
