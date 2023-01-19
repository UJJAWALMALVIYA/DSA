#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int main()
{
    int n;
    printf("ENTER THE SIZE OF ARRAY");
    scanf("%d",&n);
    int arr[MAX],temp;
    printf("ENTER THE ELEMENT OF ARRAY : ");
    for (int i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n-i-1; j++)
        {
            if (arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        printf("%d",arr[i]);
        
    }
    
    
}