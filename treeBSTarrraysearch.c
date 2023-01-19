#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int);
struct node *search(struct node *, int);

char arr[] = {'5', '3', '6', '1', '4'};
int lc[] = {1, 3, -1, -1, -1};
int rc[] = {2, 4, -1, -1, -1};
int main()
{
    struct node *root;
    root = create(0);

    printf("YOUR TRAVERSAL IS IN INORDER\n");

    inorder(root);

    char item= '5';

    struct node *found = search(root, item);

    if (found)
    {
        printf("%c value is found in the tree", found->data);
    }
    else{
        printf("%c value not found");
    }

    // insertion(root,15);
    // printf("\nYOUR TRAVERSAL IS IN INORDER\n");

    // inorder(root);
}

struct node *create(int index)
{
    struct node *temp = NULL;
    if (index != -1)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->left = create(lc[index]);
        temp->data = arr[index];
        temp->right = create(rc[index]);
    }
    return temp;
}
struct node *search(struct node *root, int item)
{

    if (root == NULL || root->data == item)
    {
        return root;
    }
    else if (root->data > item)
    {
        return search(root->left, item);
    }
    else
    {
        return search(root->right, item);
    }
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %c\t", root->data);
        inorder(root->right);
    }
}
// void insertion(struct node *root,int item)
// {
//     struct node *prev=NULL;
//     while (root != NULL)
//     {
//         prev=root;
//         if (root->data==item)
//         {
//             return root;
//         }
        
//         if (root->data > item)
//         {
//             root=root->left;
//         }
//         else{
//             root=root->right;
//         }
        
//     }
//     struct node *new=(struct node*)malloc(sizeof(struct node));
//     new->data=item;
//     new->left=new->right=NULL;
//     if (prev->data > item)
//     {
//         prev->left=new;
//     }
//     else{
//         prev->right=new;
//     }
//     return new;
    
    
// }
