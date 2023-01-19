#include<stdio.h>
#define MAX 20

int main()
{
    int  size,element,index,find,j;
    int arr[MAX];
    printf("\nENTER THE SIZE OF ARRAY\n");
    scanf("%d",&size);
    printf("\nENTER THE ELEMENTS OF ARRAY :");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }
    display(arr,size);
    printf("\nENTER THE INDEX WHERE U WANT TO INSERT",index);
    scanf("%d",&index);
    printf("\nENTER THE INSERTING VALUE",element);
    scanf("%d",&element);
    printf("\nENTER THE FINDING VALUE",find);
    scanf("%d",&find);
    // indinsert(arr,size,index,element,MAX);
    // size=size+1;
    // display(arr,size);
    // delete(arr,size,index);
    // display(arr,size);
    j=linearsearch(arr,size,find);
    printf("YOUR ELEMENT IS FOUND AT INDEX: %d",j);
}
int indinsert(int arr[],int size,int index,int element,int capacity)
{
    if (size==capacity)
    {
        printf("\nYOUR ARRAY IS FULL\n");
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
}
void display(int arr[],int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d\n",arr[i]);
    }
    
}
int delete(int arr[],int size,int index)
{
    int i;
    if (size==0)
    {
        printf("YOUR ARRAY IS EMPTY\n");
    }
    for (i = index; i < size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    return 1;
}
int linearsearch(int arr[],int size,int find)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==find)
        {
            return i;
        }
    }
    return -1;
}