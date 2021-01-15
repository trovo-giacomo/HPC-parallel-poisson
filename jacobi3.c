/* jacobi.c - Poisson problem in 3d
 * 
 */

#include <math.h>
#include <omp.h>

int jacobi3(double ***u, double ***u_old, double ***f, int N, int max_iter, double *threshold){
    int it = 0;
    double norm = 100000.0;
    double h = 1.0/6.0;
    double delta_2 = 4.0/((N-1)*(N-1));
    double ***temp;
    double error;
    //printf("Threshold: %g\n",*threshold);
    while(it < max_iter && norm > *threshold){
        temp = u_old;
        u_old = u;
        u = temp;
        // update
        error = 0.0;
        #pragma omp parallel for collapse(3) default(none) shared(u,u_old,N,delta_2,f,h) reduction(+: error)
        for(int i=1; i<N-1; i++){
            for(int j=1; j<N-1; j++){
                for(int k=1; k<N-1; k++){
                    //double t = u_old[i][j][k];

                    double t1 = u_old[i-1][j][k] + u_old[i+1][j][k];
                    t1 += u_old[i][j-1][k] + u_old[i][j+1][k];
                    t1 += u_old[i][j][k-1] + u_old[i][j][k+1];
                    t1 += delta_2*f[i][j][k];

                    u[i][j][k] = h*(t1);
                    
                    double t = u[i][j][k] - u_old[i][j][k];
                    error += t*t;
                }
            }
        }

        norm = sqrt(error);
        //norm
        //norm = frobenius_norm(u,u_old,N);
        //printf("it:%d norm:%g\n",it,norm);
        it++;
    }

    *threshold = norm;
    return it;
    
}
