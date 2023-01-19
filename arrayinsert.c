#include<stdio.h>
#define MAX 100

int main()
{
    int arr[MAX],j;
    int element,size,index;
    printf("enter the size of array");
    scanf("%d",&size);
    printf("enter the element of array");
    for (int i = 0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the index where u want ot insert",index);
    scanf("%d",&index);
    printf("enter the inserting element",element);
    scanf("%d",&element);
    j=indinsert(arr,size,element,index,MAX);
    size=size+1;
    if (j==1)
    {
        printf("YOUR INSERTION IS SUCCESSFULLY DONE");
        display(arr ,size);
    }
    else{
        printf("YOU FAILED TO INSERT");
    }
    
    
    
}

int indinsert(int arr[],int size, int element,int index, int capacity)
{
    if (size==capacity)
    {
        printf("YOUR ARRAY IS FULL\n");
    }
    for (int i = (size-1); i >=index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
    
}
void display(int arr[], int size)
{
    for (int i = 0; i<size; i++)
    {
        printf("%d\n",arr[i]);
    }
    
}