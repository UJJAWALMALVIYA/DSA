#include <stdio.h>
// #include<conio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node * create(int );

char arr[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', '\0', '\0', 'H'};
int lc[] = {1, 3, 5, -1, 9, -1, -1, -1, -1, -1};
int rc[] = {2, 4, 6, -1, -1, -1, -1, -1, -1, -1};

int main()
{
    struct node *root;

    system("cls");
    root = create(0);

    printf("YOUR TRAVERSAL IS IN INORDER\n");

    inorder(root);
    return 0;
}

struct node * create(int index)
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
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf(" %c\t",root->data);
        inorder(root->right);
    }
}