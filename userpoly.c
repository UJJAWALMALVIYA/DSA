#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
struct node{
    int exp;
    float coeff;
    int head;
    struct node *link;
};
void insert (struct node *,float,int);
void create(struct node*);
void display(struct node*);
void add(struct node *,struct node*);
int main()
{
    struct node * head=NULL;
    printf("enter the polynomial\n");
    create(head);
    display(head);
    return 0;
}
void create(struct node * head)
{
    int n,i,exp;
    float coeff;
    printf("enter the term of polynomial");
    scanf("%d",&n);
    printf("enter the coefficient and exponent of polynomial");
    for ( i = 0; i<n; i++)
    {
        scanf("%1.f",&coeff);
        scanf("%d",&exp);
        insert(head,coeff,exp);
    }
    void insert (struct node *head,float x,int y);
    struct node *temp;
    struct node *new=malloc(sizeof(struct node));
    new->coeff=coeff;
    new->exp=exp;
    new->link=NULL;
    if (head==NULL || exp > head->exp)
    {
        new->link=head;
        head=new;
    }
    else
    {
        temp=head;
        while (temp->link != NULL && temp->link->exp)
        {
            temp=temp->link;
            new->link=temp->link;
            temp->link=new;
        }
        return head;
    }
}
void display(struct node *head)
{
    if (head==NULL)
    {
        printf("NO polynomial");
    }
    else{
        struct node * temp=head;
        while (temp!=NULL)
        {
            printf("%lf x^%d",temp->coeff,temp->exp);
            temp=temp->link;
            if (temp!=NULL)
            {
                printf("+");
            }
            else
            printf("\n");
                
        }
            
    }
        
}
// void add (struct node *head1,struct node *head2)
// {
//     struct node *ptr1=head1;
//     struct node *ptr2=head2;
//     struct node *head3=NULL;
//     while (ptr1!= NULL && ptr2 != NULL)
//     {
//         if (ptr1->exp == ptr2->exp)
//         {
//             head3=insert(head3,ptr1->coeff+ptr2->coeff,ptr1->exp);
//             ptr1=ptr1->link;
//             ptr2=ptr2->link;
//         }
//         else if (ptr2->exp > ptr1->exp)
//         {
//             head3=insert(head3,ptr2->coeff,ptr2->exp);
//             ptr2=ptr2->link;
//         }
//         else if (ptr1->exp > ptr2->exp)
//         {
//             head3=insert(head3,ptr1->coeff,ptr1->exp);
//             ptr1=ptr1->link;
//         }
//     }
//     while (ptr1 != NULL)
//     {
//         head3=insert(head3,ptr1->coeff,ptr1->exp);
//         ptr1=ptr1->link;
//     }
//     while (ptr2 != NULL)
//     {
//         head3=insert(head3,ptr2->coeff,ptr2->exp);
//         ptr2=ptr2->link;
//     }
//     display(head3);
// }
