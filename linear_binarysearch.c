#include<stdio.h>
#define MAX 100
int main()
{
    int arr[MAX];
    int size,element,find,j;
    printf("enter the size of array");
    scanf("%d",&size);
    printf("enter the elements of array");
    for (int i = 0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the element you want to find");
    scanf("%d",&find);
    // linearsearch(arr,size,find);
    j=linearsearch(arr,size,find);
    printf("YOUR ELEMENT %d FOUND AT INDEX %d",find,j);
}

int linearsearch(int arr[],int size,int find)
{
    for (int i = 0; i<size; i++)
    {
        if (arr[i]==find)
        {
            return i;
        }       
        
    }
    return -1; 
    
}