#include<stdio.h>
float f(float x,float y){
    return y-x ;
}
int main()
{
    float x0 ,y0 , x , k1,k2,k3,k4 , h ;
    printf("f(x) = y-x \n");
    printf("Enter Initial Values (x0,y0) : ");
    scanf("%f%f",&x0,&y0);
    printf("Enter X : ");
    scanf("%f",&x);
    h = (x-x0) ;
    k1 = h*f(x0,y0) ;
    k2 = h*f(x0+h/2,y0+k1/2) ;
    k3 = h*f(x0+h/2,y0+k2/2) ;
    k4 = h*f(x0+h,y0+k3) ;
    float ans = y0 + (k1+2*k2+2*k3+k4)/6 ;
    printf("Answer is : %f \n",ans);
    return 0 ;
}