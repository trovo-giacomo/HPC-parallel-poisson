/* jacobi.c - Poisson problem in 3d
 * 
 */

#include "frobenius_norm.h"
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
double jacobi(double ***u, double ***u_old, double ***f, int N, int max_iter, double *threshold){
    struct timeval start, end;
    int it = 0;
    double norm = 100000.0;
    double h = 1.0/6.0;
    double delta_2 = 4.0/((N-1)*(N-1));
    double ***temp;
    double error;

    gettimeofday(&start, NULL);
    //printf("Threshold: %g\n",*threshold);
    while(it < max_iter && norm > *threshold){
        temp = u_old;
        u_old = u;
        u = temp;
        // update
        error = 0.0;
        for(int i=1; i<N-1; i++){
            for(int j=1; j<N-1; j++){
                for(int k=1; k<N-1; k++){
                    double t_old = u_old[i][j][k];
                    u[i][j][k] = h*(u_old[i-1][j][k] + u_old[i+1][j][k]+u_old[i][j-1][k] + u_old[i][j+1][k]+u_old[i][j][k-1] + u_old[i][j][k+1]+delta_2*f[i][j][k]);
                    error += (u[i][j][k] - t_old)*(u[i][j][k] - t_old);
                }
            }
        }
        norm = sqrt(error);
        //norm
        //norm = frobenius_norm(u,u_old,N);
        //printf("it:%d norm:%g\n",it,norm);
        it++;
    }
    gettimeofday(&end, NULL);
    double time_taken = end.tv_sec + end.tv_usec / 1e6 - start.tv_sec - start.tv_usec / 1e6; // in seconds
    

    *threshold = norm;
    return (double)it/time_taken;
    
}
