#include<stdio.h>
long fact(int n){
    if(n==0 || n==1){
        return 1 ;
    }
    long f = 1 ;
    while(n>1){
        f *= n;
        n-- ;
    }
    return f ;
}
int main()
{
    int t, n ;
    printf("Enter No. of Testcases : ");
    scanf("%d",&t) ;
    while(t--){
        printf("Enter N : ");
        scanf("%d",&n) ;
        printf("Factorial of %d is : %ld \n",n,fact(n));
    }
    return 0 ;
}