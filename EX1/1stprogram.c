#include<stdio.h>



double A [3][3];
double B [3][3];
double C [3][3];

int main(void){
       
        int i,j,k,m,n,p,q;
        
        printf("Enter number of rows and columns of first matrix\n");
        scanf("%d%d", &m, &n);
        printf("Enter elements of first matrix\n");
        for(i=0; i<m; i++){
            for(j=0; j<n; j++){
                printf("Enter the number for A[%d][[%d]",i,j);
                scanf("%lf",&A[i][j]);
            }
        }
        printf("Enter number of rows and columns of second matrix\n");
        scanf("%d%d", &p, &q);
        
        if (n != p)
            printf("The matrices can't be multiplied with each other.\n");
        else{
            printf("Enter elements of second matrix\n");
            for(i=0; i<p; i++){
                for(j=0; j<q; j++){
                    printf("Enter the number for B[%d][[%d]",i,j);
                    scanf("%lf",&B[i][j]);
                }
            }
        }
        
        
        for(i=0; i<m; i++){
            for(j=0; j<q; j++){
                for(k=0; k<p; k++){
                    C[i][j] = C[i][j] + (A[i][k]*B[k][j]);
                   
                }
            }
        }
        for(i=0;i<m;i++){
            for(j=0;j<q;j++){
                printf("%lf\t",C[i][j]);
            }
            printf("\n");
        }
}
