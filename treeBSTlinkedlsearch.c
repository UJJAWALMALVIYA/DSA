#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
// INITIALZING THE TREE NODE
struct node *create(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
}
// INSERTING THHE NODE IN THE USING LINKED LIST
struct node *insert(struct node *root, int item)
{
    if (root == NULL)
    {
        return create(item);
    }
    if (root->data > item)
    {
        root->left = insert(root->left, item);
    }
    else
    {
        root->right = insert(root->right, item);
    }
}
// SEARCHING ITEM IN THE TREE
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
// SEARCHING ITERATION ITEM IN THE TREE
struct node *searchiteration(struct node *root, int item)
{
    while (root != NULL)
    {
        if (root->data == item)
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
    return root;
}
// INSERTION ITEM IN THE TREE
void insertion(struct node *root, int item)
{
    struct node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == item)
        {
            return root;
        }

        if (root->data > item)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct node *new = create(item);
    if (prev->data > item)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
// INORDER PREDECESOOR FUNTION TO FIND ANY ITEM PRECEEDING ITEM
struct node *inorderpredessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

// DELETION ITEM IN THE TREE
struct node *deletenode(struct node *root, int item)
{
    struct node *ipre;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (item < root->data)
    {
        root->left = deletenode(root->left, item);
    }
    else if (item > root->data)
    {
        root->right = deletenode(root->right, item);
    }
    else
    {
        ipre = inorderpredessor(root);
        root->data = ipre->data;
        root->left = deletenode(root->left, ipre->data);
    }
    return root;
}

int main()
{
    struct node *root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 4);

    struct node *found = search(root, 4);
    if (found != NULL)
    {
        printf("\nYOUR ITEM IS FOUND %d", found->data);
    }
    else
    {
        printf("\nYOUR ITEM IS NOT FOUND");
    }

    struct node *searched = searchiteration(root, 5);
    if (searched != NULL)
    {
        printf("\nYOUR ITEM IS FOUND %d", searched->data);
    }
    else
    {
        printf("\nYOUR ITEM IS NOT FOUND");
    }

    insertion(root, 15  );
    deletenode(root, 15);

    printf("\nYOUR INORDER TRAVERSAL IS: ");
    inorder(root);
    printf("\nYOUR PREORDER TRAVERSAL IS: ");
    preorder(root);
    printf("\nYOUR POSTORDER TRAVERSAL IS: ");
    postorder(root);

    return root;
}
// TRAVERSAL OF TREE IN INORDER
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->data);
        inorder(root->right);
    }
}
// TRAVERSAL OF TREE IN PREORDER
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
// TRAVERSAL OF TREE IN POSTORDER
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->data);
    }
}
