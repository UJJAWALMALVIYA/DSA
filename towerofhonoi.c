// #include<stdio.h>
// void tower(int n,int a,int b,int c)
// {
//     if (n<=0)
//     {
//         printf("ILLEAGAL ENTRY");
//     }
//     else if(n==1)
//     {
//         printf("MOVE THE DISC FROM %d TO %d\n",a,c);
//     }
//     else
//     {
//         tower(n-1,a,c,b);
//         tower(1,a,b,c);
//         tower(n-1,b,a,c);
//     }
// }
// int main()
// {
//     tower(4,1,2,3);
//     return 0;
// }

#include<stdio.h>
void TOH(int n,int a,int b,int c)
{
    if (n>0)
    {
        TOH(n-1,a,c,b);
        printf("MOVE DISC FROM %d TO %d\n",a,c);
        TOH(n-1,b,a,c);
    }
    
} 
int main()
{
    TOH(4,1,2,3);
    return 0;
}