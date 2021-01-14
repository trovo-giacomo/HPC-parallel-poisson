#include <omp.h>

int discr(double x, int N){
    return (int) ((((double)N-1.0)/2.0*(x + 1.0))+0.5); //rounding to the nearest integer
    //(int) round((N-1)/2*(x+1))
}

void init_matrix_u_para(int N, double ***A, double start_T){
    #pragma omp parallel default(none) shared(N, A, start_T)
    {
    #pragma omp for
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<N; k++)
                A[i][j][k] = start_T;

    #pragma omp for nowait
    for(int i=0; i<N; i++)
        for(int k=0; k<N; k++){
            A[i][0][k] = 20.0;
            A[i][N-1][k] = 20.0;
        }

    #pragma omp for nowait
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            A[i][j][0] = 20.0;
            A[i][j][N-1] = 20.0;
        }

    #pragma omp for nowait
    for(int j=0; j<N; j++)
        for(int k=0; k<N; k++){
            A[0][j][k] = 0.0;
            A[N-1][j][k] = 20.0;
        }
    }/* end omp parallel */
}

void init_matrix_f_para(int N, double ***A){
    int z_start = discr(-2/3.0,N), z_end = discr(0,N);
    int y_start = discr(-1,N), y_end = discr(-1.0/2.0,N);
    int x_start = discr(-1,N), x_end = discr(-3.0/8.0,N);

    #pragma omp parallel for default(none) shared(N,A, z_start,z_end, y_start, y_end, x_start, x_end)
    for(int i=z_start; i<=z_end; i++) //iterate over the z dimension
        for(int j=y_start; j<=y_end; j++) // iterate over y
            for(int k=x_start; k<=x_end; k++) // iterate over x
                A[i][j][k] = 200.0;
}


///  ---- Not parallel ----


void init_matrix_u(int N, double ***A, double start_T){
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<N; k++)
                A[i][j][k] = start_T;

    for(int i=0; i<N; i++)
        for(int k=0; k<N; k++){
            A[i][0][k] = 20.0;
            A[i][N-1][k] = 20.0;
        }

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            A[i][j][0] = 20.0;
            A[i][j][N-1] = 20.0;
        }

    for(int j=0; j<N; j++)
        for(int k=0; k<N; k++){
            A[0][j][k] = 0.0;
            A[N-1][j][k] = 20.0;
        }
}


void init_matrix_f(int N, double ***A){
    int z_start = discr(-2/3.0,N), z_end = discr(0,N);
    int y_start = discr(-1,N), y_end = discr(-1.0/2.0,N);
    int x_start = discr(-1,N), x_end = discr(-3.0/8.0,N);

    for(int i=z_start; i<=z_end; i++) //iterate over the z dimension
        for(int j=y_start; j<=y_end; j++) // iterate over y
            for(int k=x_start; k<=x_end; k++) // iterate over x
                A[i][j][k] = 200.0;
}



