#include<stdio.h>
int main()
{
    int row , col , i , j , k ;
    printf("Enter Order Of Matrix : ");
    scanf("%d%d",&row,&col) ; 
    col = col+1; // for augmented matrix 
    float arr[row][col] ;
    printf("Enter Values in Matrix \n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%f",&arr[i][j]) ;
        }
    }
    //Gauss Jordan
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(i!=j)
            {
                float p = arr[j][i]/arr[i][i] ;
                for(k=0;k<col;k++){
                    arr[j][k] = arr[j][k] - (p*arr[i][k]);
                }
            }
        }
    }
    for(i=0;i<row;i++){
        float p = arr[i][i] ;
        for(j=0;j<col;j++){
            if(arr[i][j]!=0){
                arr[i][j] = arr[i][j]/p ;
            }
        }
    }
    //Identity Matrix 
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%.1f\t",arr[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<row;i++){
        printf("x%d = %.3f \n",i+1 , arr[i][col-1]) ;
    }
    return 0 ;
}