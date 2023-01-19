#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
int height(struct node *root)
{
    if (root==NULL)
    {
        return 0;
    }
    else{
        return root->height;
    }
}
struct node *create(int item)
{
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=item;
    temp->left=temp->right=NULL;
    temp->height=1;
}
int getbalancefactor(struct node *root)
{
    if (root==NULL)
    {
        return 0;
    }
    return height(root->left)-height(root->right);
}
int max(int a,int b)
{
    return a>b?a:b;
}
struct node *rightrotate(struct node *y)
{
    struct node *x=y->left;
    struct  node *t2=x->right;

    x->right=y;
    y->left=t2;

    y->height=max(height(y->right),height(y->left))+1;
    x->height=max(height(x->right),height(x->left))+1;
    return x;
}
struct node *leftrotate(struct node *x)
{
    struct node *y=x->right;
    struct  node *t2=y->left;

    y->left=x;
    x->right=t2;

    y->height=max(height(y->right),height(y->left))+1;
    x->height=max(height(x->right),height(x->left))+1;
    return y;
}
struct node *insert(struct node *root,int item)
{
    if (root==NULL)
    {
        return create(item);
    }
    if (root->data > item)
    {
        root->left=insert(root->left,item);
    }
    if (root->data < item)
    {
        root->right=insert(root->right,item);
    }
    root->height=1+max(height(root->left),height(root->right));
    int bf=getbalancefactor(root);
    //LEFT LEFT CASE
    if (bf>1 && item<root->left->data)
    {
        return rightrotate(root);
    }
    //RIGHT RIGHT CASE
    if (bf<-1 && item>root->right->data)
    {
        return leftrotate(root);
    }
    //LEFT RIGHT CASE
    if (bf>1 && item>root->left->data)
    {
        root->left=leftrotate(root->left);
        return rightrotate(root);
    }
    //RIGHT LEFT CASE
    if (bf<-1 && item<root->right->data)
    {
        root->right=rightrotate(root->right);
        return leftrotate(root);
    }
    return root;
    
}
int main()
{
    struct node *root=NULL;
    root=insert(root,5);
    root=insert(root,3);
    root=insert(root,6);
    root=insert(root,1);
    root=insert(root,4);

    printf("THE INORDER TRAVERSAL OF AVL TREE IS :\n");

    inorder(root);
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
    
}