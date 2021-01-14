#BSUB -J Jacobi_par
#BSUB -o Jacobi_parallel%J.out
#BSUB -q hpcintro
#BSUB -n 24
#BSUB -R "rusage[mem=2048]"
#BSUB -W 45

module load studio

# define the driver name to use
# valid values: matmult_c.studio, matmult_f.studio, matmult_c.gcc or
# matmult_f.gcc
#

N=120
NUM_ITER=1000
TOLERANCE=0.0001
START_T=0.0
OUTPUT=0


OMP_NUM_THREADS=4 collect ./poisson_j1 $N $NUM_ITER $TOLERANCE $START_T $OUTPUT