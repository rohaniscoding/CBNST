#include<stdio.h>
int main() 
{
    int i , j , k ,  m , n , sum_x =0 ,sum_y = 0 , sum_xy = 0, sum_xx =0, sum_xxy= 0 , sum_x3 = 0, sum_x4 = 0 ;
    printf("Enter No. of Observations : ");
    scanf("%d",&m); n = 7 ;
    int arr[m][n] ; // x y xy x^2 
    printf("Enter %d Observations \n",m);
    for(i=0;i<m;i++){
        scanf("%d%d",&arr[i][0],&arr[i][1]);
        arr[i][2] = arr[i][0] * arr[i][1] ; // xy
        arr[i][3] = arr[i][0] * arr[i][0] ; // xx
        arr[i][4] = arr[i][3] * arr[i][1] ; // x^2y
        arr[i][5] = arr[i][3] * arr[i][0] ; // xxx
        arr[i][6] = arr[i][5] * arr[i][0] ; // xxxx
        sum_x += arr[i][0] ;
        sum_y += arr[i][1] ;
        sum_xy += arr[i][2] ;
        sum_xx += arr[i][3] ;
        sum_xxy += arr[i][4] ;
        sum_x3 += arr[i][5] ;
        sum_x4 += arr[i][6] ;
    }
    printf("X\tY\tX*Y\tX*X\tX^2*Y\tX^3\tX^4\n") ;
    printf("------------------------------------------------\n") ;
    for(i=0;i<m;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4],arr[i][5],arr[i][6]) ;
    }
    printf("------------------------------------------------\n") ;
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",sum_x,sum_y,sum_xy,sum_xx,sum_xxy,sum_x3,sum_x4) ;
    float mat[3][34] = {{m,sum_x,sum_xx,sum_y},{sum_x,sum_xx,sum_x3,sum_xy},{sum_xx,sum_x3,sum_x4,sum_xxy}} ;
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            if(i!=j){
                float p = mat[j][i]/mat[i][i] ;
                for(k=0;k<4;k++){
                    mat[j][k] = mat[j][k] - (p*mat[i][k]) ;
                }
            }
        }
    }
    float a = mat[0][3]/mat[0][0] ;
    float b = mat[1][3]/mat[1][1] ;
    float c = mat[2][3]/mat[2][2] ;
    printf("a = %f \t b = %f \t c = %f \n",a,b,c) ;
    printf("Equation : y =  %.1f + %.1fx + %.1fx^2 \n",a,b,c);
    return 0 ;
}