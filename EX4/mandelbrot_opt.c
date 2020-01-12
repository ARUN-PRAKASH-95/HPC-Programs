#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<omp.h>




void main(){
    clock_t begin = clock();
    double X_max,X_min,Y_max,Y_min,X_pixel,Y_pixel,R_Z2,I_Z2,R_func,I_func,absolute_value,R,I,R_Z,I_Z,c;
    double R_C,I_C,threshold,i,j,k;
    X_max = 1;
    X_min = -1; 
    Y_min = -2;
    Y_max = 2; 
    X_pixel = 80;
    Y_pixel = 49;
    threshold = 4;
    /*For creating the grid which has to be checked for mandelbrot*/
    double X_grid = (X_max - X_min) / X_pixel;       
    double Y_grid = (Y_max - Y_min) / Y_pixel;


#pragma omp for
for(j=0;j<=Y_pixel;j++){
        
    for(i=0;i<=X_pixel;i++){
        /*Gives center point of each pixel in the grid*/
        R = -2 + (X_grid/2) + i*X_grid;
        I = 2-(Y_grid/2) - j*Y_grid;
        R_Z = 0;
        I_Z = 0; 

        for (k=0;k<=100000;k++){
            R_Z2 = R_Z*R_Z - I_Z*I_Z;  
            I_Z2 = 2*R_Z*I_Z;
                
            R_func = R_Z2 + R;
            I_func = I_Z2 + I;
                
            absolute_value = hypot(R_func,I_func);
            R_Z = R_func;
            I_Z = I_func;
            if (absolute_value>threshold){
                break;
            }
            
        }
        if (absolute_value<threshold){
        printf("*");
        }
        else{
        printf(" ");
        }
        
    }
if(i=X_pixel){
    printf("\n");
}
        
}
clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
printf("%lf",time_spent);
}

