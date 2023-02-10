#include<stdio.h>
float f(float y,float z){
    return (44 -y -2*z)/10 ;
}
float g(float x,float z){
    return (51 -2*x -z)/10 ;
}
float h(float x,float y){
    return (61 -x -2*y)/10 ;
}
int main()
{
    printf("10x + y + 2z = 44 \n") ;
    printf("2x + 10y + z = 51 \n") ;
    printf("x + 2y + 10z = 61 \n") ;
    int n , i = 1;
    printf("Enter No. of Approximatiopn : ");
    scanf("%d",&n) ;
    float x = 0 ,  y = 0 , z = 0 ;
    while(n--)
    {
        x = f(y,z) ;
        y = g(x,z) ;
        z = h(x,y) ;
        printf("x%d = %f \n",i,x) ;
        printf("y%d = %f \n",i,y) ;
        printf("z%d = %f \n",i,z) ;
        i++ ;
    }
    return 0 ;
}