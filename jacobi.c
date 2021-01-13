/* jacobi.c - Poisson problem in 3d
 * 
 */

#include "frobenius_norm.h"

int jacobi(double ***u, double ***u_old, double ***f, int N, int max_iter, double *threshold){
    int it = 0;
    double norm = 100000.0;
    double h = 1/6;
    double delta_2 = 4/(N*N);
    double ***temp;
    while(it < max_iter && norm > *threshold){
        temp = u_old;
        u_old = u;
        u = temp;

        // update
        for(int i=1; i<N-1; i++){
            for(int j=1; j<N-1; j++){
                for(int k=1; k<N-1; k++){
                    u[i][j][k] = h*(u_old[i-1][j][k]+u_old[i+1][j][k] + u_old[i][j-1][k]+u_old[i][j+1][k] + u_old[i][j][k-1] +u_old[i][j][k+1] + delta_2*f[i][j][k]);
                }
            }
        }

        //norm
        norm = frobenius_norm(u,u_old,N);
        
        it++;
    }

    *threshold = norm;
    return it;
    
}
