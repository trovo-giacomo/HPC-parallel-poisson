#BSUB -J Different_N
#BSUB -o Different_N_%J.out
#BSUB -q hpcintro
#BSUB -n 1
#BSUB -R "rusage[mem=2048]"
#BSUB -W 45

# module load studio

# define the driver name to use
# valid values: matmult_c.studio, matmult_f.studio, matmult_c.gcc or
# matmult_f.gcc
#
for N in 10 20  #30 40 50 60 70 80 90 100
do
    ./poisson_j $N 20000 0.0001 0 0
done

