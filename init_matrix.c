void init_matrix(int N, double ***A, double start_T){
    for(int i=1; i<(N+1); i++)
        for(int j=1; j<(N+1); j++)
            for(int k=1; k<(N+1); k++)
                A[i][j][k] = start_T;
    
    /*for(int i=0; i<(N+2); i++)
        for(int j=0; j<(N+2); j++)
            for(int k=0; k<(N+2); k++)
                A[i][j][k] = start_T;
*/
    /*for(int j=0; j<(N+2); j++)
        for(int k=0; k<(N+2); k++){
            A[0][j][k] = 0.0;
            A[N+1][j][k] = 20.0;
        }*/
    for(int i=0; i<(N+2); i++)
        for(int k=0; k<(N+2); k++){
            A[i][0][0] = 20.0;
            A[i][N+1][0] = 20.0;
        }
    /*for(int i=0; i<(N+2); i++)
        for(int j=0; j<(N+2); j++){
            A[i][j][0] = 20.0;
            A[i][j][N+1] = 20.0;
        }
    */
}