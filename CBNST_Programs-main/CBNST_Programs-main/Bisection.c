#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x){
    return pow(x,3) - 5*x +1 ;
}
int main()
{
    printf("f(x) = x^3 -5x +1 \n");
    float a , b , x , a_err;
    printf("Enter Range (a b) : ");
    scanf("%f%f",&a,&b);
    if(f(a)*f(b)<0)
    {
        printf("Range is Correct \n");
        printf("Enter Allowed Error : ");
        scanf("%f",&a_err);
        x = (a+b)/2.0  ; int i = 1 ;
        while(fabs(f(x))>a_err)
        {
            printf("a = %f\t b = %f \t x%d = %f \n",a,b,i++,x) ;
            if(f(a)*f(x)<0){
                b = x ; 
            }
            else{
                a = x ;
            }
            x = (a+b)/2 ;
        }
        printf("Root of Equation = %f \n",x);
    }
    else{
        printf("!!! Range is Incorrect !!!\n");
    }
    return 0 ;
}