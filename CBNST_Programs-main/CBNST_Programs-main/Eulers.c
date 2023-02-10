#include<stdio.h>
#include<math.h>
float f(float x,float y){
    return (y-x)/(y+x) ;
}
int main()
{
    int  a, b , i ; float x0,y0 ,y1, x ,  n  , ans = 0 , h ;
    printf("Enter  Initial Values (x0,y0) : ");
    scanf("%f%f",&x0,&y0) ;
    printf("Enter X  : ");
    scanf("%f",&x) ;
    printf("Enter No. of Intervals : ");
    scanf("%f",&n);
    h = (x-x0)/n;
    for(i=0;i<n;i++)
    {
        y1 = y0 + h*f(x0,y0) ;
        printf("y%d = %f \n",i+1,y1);
        x0 = x0 + h ;
        y0 = y1 ;
    }
    printf("Answer is : %f \n",y1);
    return 0 ;
}