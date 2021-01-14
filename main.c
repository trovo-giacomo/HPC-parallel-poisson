/* main.c - Poisson problem in 3D
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "alloc3d.h"
#include "print.h"

#include "init_matrix.h"

#ifdef _JACOBI1
#include "jacobi1.h"
#endif

#ifdef _JACOBI2
#include "jacobi1.h"
#endif

#define N_DEFAULT 100

int
main(int argc, char *argv[]) {

    int 	N = N_DEFAULT;
    int 	iter_max = 1000;
    double	tolerance;
    double	start_T;
    int		output_type = 0;
    char	*output_prefix = "poisson_res";
    char        *output_ext    = "";
    char	output_filename[FILENAME_MAX];
    double 	***u = NULL, ***u_old=NULL, ***f=NULL;


    /* get the paramters from the command line */
    N         = atoi(argv[1]);	// grid size
    iter_max  = atoi(argv[2]);  // max. no. of iterations
    tolerance = atof(argv[3]);  // tolerance
    start_T   = atof(argv[4]);  // start T for all inner grid points
    if (argc == 6) {
	output_type = atoi(argv[5]);  // ouput type
    }

    // allocate memory
    if ( (u = d_malloc_3d(N, N, N)) == NULL ) {
        perror("array u: allocation failed");
        exit(-1);
    }

    init_matrix_u(N,u,start_T);

    if ( (u_old = d_malloc_3d(N, N, N)) == NULL ) {
        perror("array u: allocation failed");
        exit(-1);
    }
    init_matrix_u(N,u_old,start_T);

    if ( (f = d_malloc_3d(N, N, N)) == NULL ) {
        perror("array f: allocation failed");
        exit(-1);
    }
    init_matrix_f(N,f);

    #ifdef _JACOBI1
    printf("Jacobi executed\n");
    int tot_iteration = jacobi1(u,u_old,f,N,iter_max,&tolerance);
    #endif

    #ifdef _JACOBI2
    printf("Jacobi executed\n");
    int tot_iteration = jacobi1(u,u_old,f,N,iter_max,&tolerance);
    #endif
    
    printf("Total iteration: %d\nNorm: %g\n",tot_iteration,tolerance);

    /*for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++)
                printf("%g ",f[i][j][k]);
            printf("\n");
        }
        printf("\n");
    }

    printf("Test discretization:\n");
    printf("%d ",discr(-1,N));
    printf("%d ",discr(0,N));
    printf("%d\n",discr(1,N));
    
*/
    // dump  results if wanted 
    switch(output_type) {
	case 0:
	    // no output at all
	    break;
	case 3:
	    output_ext = ".bin";
	    sprintf(output_filename, "%s_%d%s", output_prefix, N, output_ext);
	    fprintf(stderr, "Write binary dump to %s: ", output_filename);
	    print_binary(output_filename, N, u);
	    break;
	case 4:
	    output_ext = ".vtk";
	    sprintf(output_filename, "%s_%d%s", output_prefix, N, output_ext);
	    fprintf(stderr, "Write VTK file to %s: ", output_filename);
	    print_vtk(output_filename, N, u);
        //print_vtk(output_filename, N, f);
	    break;
	default:
	    fprintf(stderr, "Non-supported output type!\n");
	    break;
    }

    // de-allocate memory
    free(u);
    free(f);

    return(0);
}
