#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int main()
{
    int n,j;
    printf("ENTER THE SIZE OF ARRAY");
    scanf("%d",&n);
    int arr[MAX],temp;
    printf("ENTER THE ELEMENT OF ARRAY");
    for (int i = 0; i <n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i<n; i++)
    {
        temp=arr[i];
        int j=i-1;
        while (j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        printf("%d",arr[j]);      
    }
    
    
}