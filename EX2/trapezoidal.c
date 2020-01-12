#include<stdio.h>

double func;


double f(double *x){
    func = 1/(1+((*x)*(*x));
    return func;
}

int main(){
        double a,b;
        int n,i;
        double x;
        double s;
        double h,answer;
       

        a = 0;
        b = 1;
        printf("Enter the number of trapezoids you want\n");
        scanf("%d",&n);
        h = (b-a)/n;
        
        
        for(i=1;i<n;i++){
            x = a + i*h;
            s = s + f(&x);
        }
        
        answer = (h/2)*(f(*&a)+f(&b)+2*s);
        printf("%lf\n",answer*4);
        
        
}