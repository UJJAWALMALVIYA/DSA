#include<stdio.h>
long int numberfact(int n)
{
    if (n==0)
    {
        return 1;
    }
    else{ 
        return n*numberfact(n-1);
    }
    
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%ld",numberfact(n));
       return 0;
}

// #include<stdio.h>
// long int multiplyNumbers(int n);
// int main() {
//     int n;
//     printf("Enter a positive integer: ");
//     scanf("%d",&n);
//     printf("Factorial of %d = %ld", n, multiplyNumbers(n));
//     return 0;
// }

// long int multiplyNumbers(int n) {
//     if (n>=1)
//         return n*multiplyNumbers(n-1);
//     else
//         return 1;
// }
