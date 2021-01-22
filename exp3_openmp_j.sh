#BSUB -J Jacobi_par
#BSUB -o Jacobi_parallel%J.out
#BSUB -q hpcintro
#BSUB -gpu "num=1:mode=exclusive_process"
#BSUB -n 12
#BSUB -R "rusage[mem=2048]"
#BSUB -W 45

# module load studio

# define the driver name to use
# valid values: matmult_c.studio, matmult_f.studio, matmult_c.gcc or
# matmult_f.gcc
#

N=500
NUM_ITER=1000
TOLERANCE=0.0001
START_T=0.0
OUTPUT=0

PLACE=sockets
BIND=spread

THREAD="16"
EXE="./poisson_j4"
for EX in $EXE
do
echo "Executable: $EX sockets spread"
for THR in $THREADS
do
# echo "Number of threads: $THR"
    OMP_PLACES=$PLACE OMP_PROC_BIND=$BIND OMP_NUM_THREADS=$THR time --format=%e $EX $N $NUM_ITER $TOLERANCE $START_T $OUTPUT
    #OMP_NUM_THREADS=$THR $EX $N $NUM_ITER $TOLERANCE $START_T $OUTPUT
done
done

#for N in 100 200 300 400
#do
#    OMP_NUM_THREADS=1 time -p ./poisson_j1 $N $NUM_ITER $TOLERANCE $START_T $OUTPUT
#done
