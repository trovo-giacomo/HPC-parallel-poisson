# Makefile
#
TARGET_J1  = poisson_j1		# Jacobi1
TARGET_J2  = poisson_j2		# Jacobi2

SOURCES	= main.c print.c alloc3d.c init_matrix.c frobenius_norm.c
OBJECTS	= print.o alloc3d.o init_matrix.o frobenius_norm.o
MAIN_J	= main_j.o
MAIN_GS = main_gs.o
OBJS_J	= $(MAIN_J1) jacobi1.o
OBJS_J	= $(MAIN_J2) Jacobi2.o

# options and settings for the GCC compilers
#
CC	= gcc
DEFS	= 
OPT	= -g -O3
IPO	= 
ISA	= 
CHIP	= 
ARCH	= 
PARA	= -fopenmp
CFLAGS	= $(DEFS) $(ARCH) $(OPT) $(ISA) $(CHIP) $(IPO) $(PARA) $(XOPTS)
LDFLAGS = -lm 

all: $(TARGET_J2) $(TARGET_J2) 

$(TARGET_J2): $(OBJECTS) $(OBJS_J)
	$(CC) -o $@ $(CFLAGS) $(OBJS_J) $(OBJECTS) $(LDFLAGS)

$(TARGET_J2): $(OBJECTS) $(OBJS_GS)
	$(CC) -o $@ $(CFLAGS) $(OBJS_GS) $(OBJECTS) $(LDFLAGS)

$(MAIN_J1):
	$(CC) -o $@ -D_JACOBI1 $(CFLAGS) -c main.c 

$(MAIN_J2):
	$(CC) -o $@ -D_JACOBI2 $(CFLAGS) -c main.c 

clean:
	@/bin/rm -f core *.o *~

realclean: clean
	@/bin/rm -f $(TARGET_J2)  $(TARGET_J2)

clean_vtk:
	@/bin/rm -f *.vtk

# DO NOT DELETE

main_j.o: main.c print.h jacobi.h init_matrix.h
main_gs.o: main.c print.h gauss_seidel.h init_matrix.h
print.o: print.h
