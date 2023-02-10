#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x){
    return pow(x,3) - 5*x +1 ;
}
int main()
{
    printf("f(x) = x^3 -5x +1 \n");
    float x0 , x1 , x , a_err;
    printf("Enter Range (a b) : ");
    scanf("%f%f",&x0,&x1);
    if(f(x0)*f(x1)<0)
    {
        printf("Range is Correct \n");
        printf("Enter Allowed Error : ");
        scanf("%f",&a_err);
        int i = 2 ; float x2 ;
        do
        {
            x2 = x0 - (x1-x0)*f(x0)/(f(x1)-f(x0)) ;
            printf("x0 = %f\t x1 = %f \t x%d = %f \n",x0,x1,i++,x2) ;
            if(f(x0)*f(x2)<0){
                x1 = x2 ; 
            }
            else{
                x0 = x2 ;
            }
        }while(fabs(f(x2))>a_err);
        printf("Root of Equation = %f \n",x2);
    }
    else{
        printf("!!! Range is Incorrect !!!\n");
    }
    return 0 ;
}