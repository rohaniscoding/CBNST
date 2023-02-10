#include<stdio.h>
int fact(int n){
    int f = 1 ;
    if(n==0 || n==1){
        return f ;
    }
    while(n>1){
        f *= n ;
        n-- ;
    }
    return f ;
}
int main()
{
    int m ,n , i , j ;
    printf("Enter No. of Observations : ");
    scanf("%d",&m) ; n = m+1 ;
    int arr[m][n] ; float x , a , h ,u , fa ;
    printf("Enter %d Observations (x,y)\n",m) ;
    for(i=0;i<m;i++){
        scanf("%d%d",&arr[i][0],&arr[i][1]);
    }
    printf("Enter X : ");
    scanf("%f",&x) ;
    //Calculating Forward Difference
    int k = 1 ;
    for(i=2;i<n;i++)
    {
        int p = 0 ;
        while(p<m-k)
        {
            arr[p][i] = arr[p+1][i-1] - arr[p][i-1] ;
            p++ ;
        }
        k++ ;
    }
    k = 0 ;
    for(i=0;i<m;i++){
        for(j=0;j<n-k;j++){
            printf("%d\t",arr[i][j]) ;
        }
        k++;
        printf("\n");
    }
    h = arr[1][0] - arr[0][0] , a = arr[0][0] , fa = arr[0][1] ;
    u = (x-a)/h  ;// x = a + hu
    float u_val[n-2] ; u_val[0] = u ;
    for(i=1;i<n-2;i++){
        u_val[i] = u_val[i-1]*(u-i) ;
    }
    float ans = 0 ;
    ans += fa ;
    for(i=0;i<m;i++){
        ans += u_val[i]*arr[0][i+2]/ fact(i) ;
    }
    printf("Answer is : %f \n",ans) ;
    return 0 ;
}