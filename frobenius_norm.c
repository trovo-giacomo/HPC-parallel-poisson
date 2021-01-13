#include <math.h>
double frobenius_norm(double ***u, double ***u_old, int N){
    double sum = 0.0;
    for(int i=1; i<N-1; i++){
        for(int j=1; j<N-1; j++){
            for(int k=1; k<N-1; k++){
                sum += (u[i][j][k] - u_old[i][j][k]) * (u[i][j][k] - u_old[i][j][k]);
            }
        }
    }
    return sqrt(sum);
}