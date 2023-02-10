#include<stdio.h>
int main()
{
    int m , n , i , j , k ;
    printf("Enter No. of Observations : ");
    scanf("%d",&m) ; n = 5 ;
    int arr[m][n] ;
    printf("Enter %d Observations \n",m) ;
    int sum_x = 0 , sum_y = 0 , sum_xy = 0 , sum_xx = 0 , sum_yy = 0;
    for(i=0;i<m;i++){
        scanf("%d%d",&arr[i][0],&arr[i][1]) ;
        arr[i][2] = arr[i][0] * arr[i][1] ; // xy
        arr[i][3] = arr[i][0] * arr[i][0] ; // xx 
        arr[i][4] = arr[i][1] * arr[i][1] ; // yy 
        sum_x += arr[i][0] ; 
        sum_y += arr[i][1] ;
        sum_xy += arr[i][2] ;
        sum_xx += arr[i][3] ;
        sum_yy += arr[i][4] ;
    }
    float mat[2][3] = {{m,sum_x,sum_y},{sum_x,sum_xx,sum_xy}} ;
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            if(i!=j){
                float p = mat[j][i]/mat[i][i] ;
                for(k=0;k<3;k++){
                    mat[j][k] = mat[j][k] - (p*mat[i][k]) ;
                }
            }
        }
    }
    printf("X\tY\tX*Y\tX*X\tY*Y\n");
    printf("-------------------------------------\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4]) ; 
    }
    printf("--------------------------------------\n");
    printf("%d\t%d\t%d\t%d\t%d\n",sum_x,sum_y,sum_xy,sum_xx,sum_yy);
    float a = mat[0][2]/arr[0][0] ;
    float b = mat[1][2]/arr[1][1] ;
    float byx = (m*sum_xy-sum_x*sum_y)/ (float)(m*sum_xx - (sum_x*sum_x)) ;
    printf("a = %f \t b = %f \n",a,b) ;
    printf("Regression Coefficient = %f \n",byx) ;
    printf("Regression Line : y = %.2f + %.2fx \n",a,b) ;
    return 0 ;
}