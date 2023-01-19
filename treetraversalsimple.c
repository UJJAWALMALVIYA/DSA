#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int item)
{
    struct node *p=(struct node *)malloc(sizeof(struct node));
    p->data=item;
    p->left=NULL;
    p->right=NULL;
}

int main()
{
    struct node *p=createnode(4);
    struct node *p1=createnode(1);
    struct node *p2=createnode(5);
    struct node *p3=createnode(2);
    struct node *p4=createnode(6);

    p->left=p1;
    p->right=p4;
    p1->left=p2;
    p1->right=p3;

    inorder(p);
    printf("\n");
    preorder(p);
    printf("\n");
    postorder(p);
}
 void inorder(struct node *root)
 {
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
    
 }
 void preorder(struct node *root)
 {
    if (root != NULL)
    {
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
 }
 void postorder(struct node *root)
 {
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
    
 }