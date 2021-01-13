/* gauss_seidel.h - Poisson problem
 *
 */
#ifndef _GAUSS_SEIDEL_H
#define _GAUSS_SEIDEL_H

// define your function prototype here
int gauss_seidel(double ***u, double ***f, int N, int max_iter, double *threshold);

#endif
