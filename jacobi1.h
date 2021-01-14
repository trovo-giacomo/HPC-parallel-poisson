/* jacobi.h - Poisson problem 
 *
 * $Id: jacobi.h,v 1.1 2006/09/28 10:12:58 bd Exp bd $
 */

#ifndef _JACOBI_H1
#define _JACOBI_H1

int jacobi1(double ***u, double ***u_old, double ***f, int N, int max_iter, double *threshold);

#endif

