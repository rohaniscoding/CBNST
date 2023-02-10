#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double f(double x){
    // return (cos(x) -3*x +1)  ;
    return (pow(x,3) -5*x +1) ;
}
double dx(double x){
    // return (3+ sin(x)) ;
    return 3* pow(x,2) -5 ; 
}
int main()
{
    printf("f(x) = x^3 -5x +1  \n");
    double x0 , x1 , a , b  , i ,  a_err; int k = 1 ;
    printf("Enter Range : ");
    scanf("%lf%lf",&a,&b);
    if(f(a)*f(b)<0)
    {
        printf("Range is Correct \n");
        printf("Enter Allowed Error : ");
        scanf("%lf",&a_err);
        x0 = (a+b)/2.0 ;
        printf("x0 = %f \n",x0) ;
        printf("f(x) = %f \t d(x) = %f \n",f(x0),dx(x0)) ;
        while(fabs(f(x0))>a_err && k<11)
        {
            x1 = x0 - f(x0)/dx(x0) ;
            printf("x%d = %lf \n",k++,x1) ;
            x0 = x1 ;
        }
        printf("Root of Equation = %lf \n",x0) ;
    }
    return 0 ;
}