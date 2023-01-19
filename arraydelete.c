#include<stdio.h>
#define MAX 100

int main()
{
    int arr[MAX],j;
    int size,index;
    printf("enter the size of array");
    scanf("%d",&size);
    printf("enter the element of array");
    for (int i = 0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the index where u want to delete",index);
    scanf("%d",&index);
    // printf("enter the inserting element",element);
    // scanf("%d",&element);
    j=inddelete(arr,size,index,MAX);
    size=size-1;
    if (j==1)
    {
        printf("YOUR DELETION IS SUCCESSFULLY DONE");
        display(arr ,size);
    }
    else{
        printf("YOU FAILED TO DELETE");
    }
  
}
inddelete(int arr[],int size,int index,int capacity)
{
    if (size==0)
    {
        printf("NO ELEMENT IN ARRAY");
    }
    for (int i = index; i<(size-1); i++)
    {
        arr[i]=arr[i+1];
    }
    return 1;
    
}
void display(int arr[], int size)
{
    for (int i = 0; i<size; i++)
    {
        printf("%d\n",arr[i]);
    }
    
}
