#BSUB -J Jacobi_par
#BSUB -o Jacobi_parallel%J.out
#BSUB -q hpcintro
#BSUB -n 24
#BSUB -R "rusage[mem=2048]"
#BSUB -W 45

# module load studio

# define the driver name to use
# valid values: matmult_c.studio, matmult_f.studio, matmult_c.gcc or
# matmult_f.gcc
#

#N = 100
NUM_ITER=1000000
TOLERANCE=0.0001
START_T=0.0
OUTPUT=0

#THREADS = 1 2 4 6 8 10 12 14 16 18 20 22 24
#for THR in $THREADS
#do
#    OMP_NUM_THREADS=$THR time -p ./poisson_j $N $NUM_ITER $TOLERANCE $START_T $OUTPUT
#done
for N in 100 200 300 400
do
    OMP_NUM_THREADS=1 time -p ./poisson_j $N $NUM_ITER $TOLERANCE $START_T $OUTPUT
done
