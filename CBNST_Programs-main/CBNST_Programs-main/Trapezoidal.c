#include<stdio.h>
#include<math.h>
float f(float x){
    return 1/(pow(x,3)+10) ;
}
int main()
{
    int  a , b ;
    printf("Enter a and b ");
    scanf("%d%d",&a,&b) ;
    float n , i , ans = 0 , h ;
    printf("Enter No. of Intervals : ");
    scanf("%f",&n);
    h = (b-a)/n ;
    ans =  f(a) + f(b) ;
    for(i=a+h;i<b;i=i+h){
        ans += 2*f(i) ;
    }
    ans = (ans*h)/2.0 ;
    printf("Answer is : %f \n",ans);
    return 0 ;
}