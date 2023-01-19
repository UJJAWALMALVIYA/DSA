// #include <stdio.h>

// int main(void) {
// 	// your code goes here
 
//  int t=0;
//  scanf("%d",&t);
//  while(t>0)
//  {
//   int arr[100000]={0};
//     int i,size, sum=0,count;

//    // printf("Enter size of the array : ");
//     scanf("%d", &size);


//     //printf("Enter elements in array : ");
//     for(i=0; i<size; i++)
//     {
//         scanf("%d", &count);
//         arr[count]++;

//     }

//     for(i=0; i<100000; i++)
//     {
//         if(arr[i]!=0)
//         {
//         if (arr[i]>sum)
//          sum=arr[i];
//         }
//     }

//     printf("%d",size-sum);
//     printf("\n");
//     t--;
// }
// 	return 0;



#include<stdio.h>
main()
{
    int t;
    scanf("%d",&t);
    while(t--)
	{
        int n;
        double arr[100];
        scanf("%d", &n);

        for (int i = 0; i < n; ++i) {
          scanf("%lf", &arr[i]);
        }
        for (int i = 1; i < n; ++i) {
          if (arr[0] < arr[i]) {
            arr[0] = arr[i];
          }
        }

        printf(" %.0lf", arr[0]);

        return 0;
	      }
}