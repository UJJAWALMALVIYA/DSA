#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int item)
{
    struct node *root=(struct node*)malloc(sizeof(struct node));
    root->data=item;
    root->left=NULL;
    root->right=NULL;
}

struct node *insert(struct node *root,int item)
{
    if (root == NULL)
    {
        return create(item);
    }
    if (item< root->data)
    {
        root->left=insert(root->left,item);
    }
    else
    {
        root->right=insert(root->right,item);
    }
    
    return root;
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

int main()
{
    struct node *root=NULL;
    root=insert(root,5);
    root=insert(root,3);
    root=insert(root,6);
    root=insert(root,1);
    root=insert(root,4);
    
    printf( "YOUR INORDER TRAVERSAL IS :");
    inorder(root);
    printf("\n");
    printf( "YOUR PREORDER TRAVERSAL IS :");
    preorder (root);
    printf("\n");
    printf("YOUR POSTORDER TRAVERSAL IS :");
    postorder(root);
    
}
