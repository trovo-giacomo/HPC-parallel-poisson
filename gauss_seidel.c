/* gauss_seidel.c - Poisson problem in 3d
 *
 */
#include <math.h>
#include "frobenius_norm.h"
#include <time.h>
#define mytimer clock
#define delta_t(a,b) (1e3 * (b - a) / CLOCKS_PER_SEC)


int gauss_seidel(double ***u, double ***f, int N, int max_iter, double *threshold) {
    int it = 0;
    double norm = 1000.0; //, norm_old = 0, tollerance = 1000;
    double h = 1.0/6.0;
    double delta_2 = 4.0/(N*N), error;
    clock_t t1 ,t2, total;

    t1 = mytimer();

    while(it < max_iter && norm > *threshold){
        error = 0.0;
        // update
        for(int i=1; i<N-1; i++){
            for(int j=1; j<N-1; j++){
                for(int k=1; k<N-1; k++){
                    double u_old =  u[i][j][k];
                    u[i][j][k] = h*(u[i-1][j][k]+u[i+1][j][k] + u[i][j-1][k]+u[i][j+1][k] + u[i][j][k-1] +u[i][j][k+1] + delta_2*f[i][j][k]);

                    error += (u[i][j][k] - u_old) * (u[i][j][k] - u_old);
                }
            }
        }
        norm = sqrt(error);
        //norm
        //norm = frobenius_norm_single(u,N);
        //tollerance = fabs(norm-norm_old);
        //printf("it:%d norm:%g\n",it,norm);
        it++;
    }
    t2 = mytimer();
    total = delta_t(t1,t2);
    printf("%f\n",total);

    *threshold = norm;
    return it;
    
}

