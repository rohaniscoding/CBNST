#include<stdio.h>
#include<math.h>
float f(float x){
    return 1/(pow(x,2)+1) ;
}
int main()
{
    int  a , b ;
    printf("Enter a and b : ");
    scanf("%d%d",&a,&b) ;
    float n , i , ans = 0 , h ;
    printf("Enter No. of Intervals : ");
    scanf("%f",&n);
    h = (b-a)/n ; int k =1 ;
    ans =  f(a) + f(b) ;
    for(i=a+h;i<b;i=i+h){
        if(k%3!=0){
            ans += 3*f(i) ;
        }
        else{
            ans += 2*f(i) ;
        }
        k++ ;
    }
    ans = (ans*3*h)/8.0 ;
    printf("Answer is : %f \n",ans);
    return 0 ;
}