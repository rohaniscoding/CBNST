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
    //Gauss Elimination
    for(k=0;k<row;k++)
    {
        for(i=k+1;i<col;i++)
        {
            float p = arr[i][k]/arr[k][k] ;
            for(j=0;j<col;j++)
            {
                arr[i][j] = arr[i][j] - (p*arr[k][j]) ;
            }
        }
    }
    //BackTrack ;
    float x[col] ;
    x[col-1] = 0 ;
    for(i=row-1;i>=0;i--)
    {
        float sum = 0 ;
        for(j=i+1;j<col;j++){
            sum += arr[i][j] * x[j] ;
        }
        x[i] = (arr[i][col-1] - sum)/arr[i][i] ;
    }
    //Upper Triangular Matrix 
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%.1f\t",arr[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<row;i++){
        printf("x%d = %.3f \n",i+1,x[i]) ;
    }
    return 0 ;
}