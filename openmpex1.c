#include <stdio.h>
#include <math.h>
#include <omp.h>

#define N 100000000

int main() {
    double sum = 0;

    double tbegin = omp_get_wtime();
    printf("time %f\n", tbegin);
    omp_set_num_threads(10);
    #pragma omp parallel for reduction( +: sum )
    for ( int i = 0; i < N; i++ ) {
        sum += cos( i );
    }
    double wtime = omp_get_wtime() - tbegin;

    printf( "Computing %d cosines and summing them with %d threads took %fs\n",
            N, omp_get_max_threads(), wtime );

    printf("%f\n",sum);

    return sum;
}