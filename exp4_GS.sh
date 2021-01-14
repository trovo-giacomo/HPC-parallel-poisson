#BSUB -J Gauss_Sidel_par
#BSUB -o GaussSidel_parallel%J.out
#BSUB -q hpcintro
#BSUB -n 24
#BSUB -R "rusage[mem=2048]"
#BSUB -W 45

# module load studio

# define the driver name to use
# valid values: matmult_c.studio, matmult_f.studio, matmult_c.gcc or
# matmult_f.gcc
#

N=120
NUM_ITER=8000
TOLERANCE=0.0001
START_T=0.0
OUTPUT=0

PLACE=sockets
BIND=spread

THREADS="1 2 4 6 8 10 12 14 16 18 20 22 24"
#THREADS="6 8 10"
EXE="./poisson_gs"
for EX in $EXE 
do
echo "Executable: $EX"
for THR in $THREADS
do
echo "Number of threads: $THR"
    OMP_PLACES=$PLACE OMP_PROC_BIND=$BIND OMP_NUM_THREADS=$THR time --format=%e $EX $N $NUM_ITER $TOLERANCE $START_T $OUTPUT
    #OMP_NUM_THREADS=$THR time --format=%e $EX $N $NUM_ITER $TOLERANCE $START_T $OUTPUT
done
done

#for N in 100 200 300 400
#do
#    OMP_NUM_THREADS=1 time -p ./poisson_j1 $N $NUM_ITER $TOLERANCE $START_T $OUTPUT
#done
