#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double mandelbrot(double x,double y);

void main(){
    double X_max,X_min,Y_max,Y_min,X_pixel,Y_pixel,R_Z2,I_Z2,R_func,I_func,absolute_value,R,I,R_Z,I_Z,c;
    double R_C,I_C,threshold,i,j,k;
    X_max = 2;
    X_min = -2; 
    Y_min = -2;
    Y_max = 2; 
    X_pixel = 80;
    Y_pixel = 49;
    threshold = 4;
    double X_grid = (X_max - X_min) / X_pixel;
    double Y_grid = (Y_max - Y_min) / Y_pixel;
    
    /*printf("%lf",X_grid);*/
    
    double mandelbrot(double x,double y){
        
        R_Z = 0;
        I_Z = 0; 
       
        for (k=0;k<=100000;k++){
            R_Z2 = R_Z*R_Z - I_Z*I_Z;
            I_Z2 = 2*R_Z*I_Z;
            
            R_func = R_Z2 + x;
            I_func = I_Z2 + y;
            
            absolute_value = hypot(R_func,I_func);
             /*printf("%lf\t",absolute_value);*/
            R_Z = R_func;
            I_Z = I_func;
        }
        /*printf("%lf\t",absolute_value);*/
        return absolute_value;
    }
    
    for(j=0;j<=Y_pixel;j++){
        
        for(i=0;i<=X_pixel;i++){
            R = -2 + (X_grid/2) + i*X_grid;
            I = 2-(Y_grid/2) - j*Y_grid;
            c = mandelbrot(R,I);
            if (c<threshold){
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
}