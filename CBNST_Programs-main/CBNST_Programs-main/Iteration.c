#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double f(double x){
    return (1+cos(x))/3 ;
}
double dx(double x){
    return -sin(x)/3 ;
}
int main()
{
    printf("f(x) = cos(x) -3x +1  \n");
    double x0 , x1 , x , i ,  a_err; int n , k = 1 ;
    printf("Enter Number of Iterations : ");
    scanf("%d",&n);
    while(dx(i)>1){
        i++ ;
    }
    x0 = i ;
    printf("x0 = %f \n",x0) ;
    while(n--)
    {
        x1 = f(x0) ;
        printf("x%d = %f \n",k++,x1) ;
        x0 = x1 ;
    }
    printf("Root of Equation = %f \n",x1) ;
    return 0 ;
}