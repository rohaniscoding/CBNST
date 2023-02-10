#include<stdio.h>
int main()
{
    int m , i ; float x ;
    printf("Enter No. of Obeservations : ");
    scanf("%d",&m) ;
    int arr[m][2] ;
    printf("Enter %d Obseravtions (x,y)\n",m);
    for(i=0;i<m;i++){
        scanf("%d%d",&arr[i][0],&arr[i][1]);
    }
    printf("Enter X : ");
    scanf("%f",&x);
    for(i=0;i<m;i++){
        printf("%d\t%d\n",arr[i][0],arr[i][1]);
    }
    float ans = 0 ,  num , den , count = m ;
    int ind = 0 ;
    while(count--)
    {
        num = 1 , den = 1 ;
        for(i=0;i<m;i++)
        {
            if(i!=ind)
            {
                num = num * (x-arr[i][0]) ;
            }
        }
        num = num * arr[ind][1];
        float p = arr[ind][0] ;
        for(i=0;i<m;i++)
        {
            if(i!=ind)
            {
                den = den * (p - arr[i][0]) ;
            } 
        }
        ind++;
        ans += num/den ;
    }
    printf("Answer is : %f \n",ans) ;
    return 0 ;
}
// 5  6  9  11
// 12 13 14 16
// x = 10