/* jacobi.h - Poisson problem 
 *
 * $Id: jacobi.h,v 1.1 2006/09/28 10:12:58 bd Exp bd $
 */

#ifndef _JACOBI_H1
#define _JACOBI_H1

int jacobi1(double ***u, double ***u_old, double ***f, int N, int max_iter, double *threshold);

#endif

#ifndef _JACOBI_H2
#define _JACOBI_H2

int jacobi2(double ***u, double ***u_old, double ***f, int N, int max_iter, double *threshold);

#endif

#ifndef _JACOBI_H3
#define _JACOBI_H3

int jacobi3(double ***u, double ***u_old, double ***f, int N, int max_iter, double *threshold);

#endif

#ifndef _JACOBI_4
#define _JACOBI_4

int jacobi4(double ***u, double ***u_old, double ***f, int N, int max_iter, double *threshold);

#endif

#ifndef _JACOBI_5
#define _JACOBI_5

int jacobi5(double ***u, double ***u_old, double ***f, int N, int max_iter, double *threshold);

#endif
