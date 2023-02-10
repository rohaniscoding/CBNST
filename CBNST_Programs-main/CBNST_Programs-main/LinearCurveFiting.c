#include<stdio.h>
int main() 
{
    int i , j , k ,  m , n , sum_x =0 ,sum_y = 0 , sum_xy = 0, sum_xx =0 ;
    printf("Enter No. of Observations : ");
    scanf("%d",&m); n = 4 ;
    int arr[m][n] ; // x y xy x^2 
    printf("Enter %d Observations \n",m);
    for(i=0;i<m;i++){
        scanf("%d%d",&arr[i][0],&arr[i][1]);
        arr[i][2] = arr[i][0] * arr[i][1] ; // xy
        arr[i][3] = arr[i][0] * arr[i][0] ; // xx
        sum_x += arr[i][0] ;
        sum_y += arr[i][1] ;
        sum_xy += arr[i][2] ;
        sum_xx += arr[i][3] ;
    }
    printf("X\tY\tX*Y\tX*X\n") ;
    printf("-----------------------------\n") ;
    for(i=0;i<m;i++){
        printf("%d\t%d\t%d\t%d\n",arr[i][0],arr[i][1],arr[i][2],arr[i][3]) ;
    }
    printf("-----------------------------\n") ;
    printf("%d\t%d\t%d\t%d\n",sum_x,sum_y,sum_xy,sum_xx) ;
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
    float a = mat[0][2]/mat[0][0] ;
    float b = mat[1][2]/mat[1][1] ;
    printf("a = %f \t b = %f \n",a,b) ;
    printf("Equation : y =  %.2f + %.2fx \n",a,b);
    return 0 ;
}