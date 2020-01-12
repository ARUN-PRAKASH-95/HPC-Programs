#include <stdio.h>
#include <omp.h>
// #include <time.h>
#include <pthread.h>
#define NTHREADS 2

int main(){
    int a[1000000],i;
    // double start_time = omp_get_wtime();
    // clock_t begin = clock();
    
    // #pragma omp parallel for
    for(i=0;i<1000000;i++){
        a[i] = i;
    }


    // double time = omp_get_wtime() - start_time;
    // clock_t end = clock();
    // double time = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("%lf",time);
    return 0;
}