#include<stdio.h>
#define MAX 100
int main ()
{
    int arr[MAX];
    int size,element,find,j;
    printf("enter the size of array");
    scanf("%d",&size);
    printf("enter the element of array");
    for (int i = 0; i < size; i++)
    {
       scanf("%d",&arr[i]);
    }
    printf("enter the element you want to find of array");
    scanf("%d",&find);
    j=binarysearch(arr,size,find);
    printf("yes your item found at %d",j);

}
int binarysearch(int arr[],int size,int find)
{
    int mid;
    int low=0;
    int high=size-1;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (arr[mid]==find)
        {
            return mid;
        }
        if (arr[mid]<find)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        
        
    }
    return -1;
    
}