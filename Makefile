# Makefile
#
TARGET_J1  = poisson_j1		# Jacobi1
TARGET_J2  = poisson_j2		# Jacobi2

SOURCES	= main.c print.c alloc3d.c init_matrix.c
OBJECTS	= print.o alloc3d.o init_matrix.o 
MAIN_J1	= main_j1.o
MAIN_J2 = main_j2.o
OBJS_J1	= $(MAIN_J1) jacobi1.o
OBJS_J2	= $(MAIN_J2) jacobi2.o

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

all: $(TARGET_J1) $(TARGET_J2) 

$(TARGET_J1): $(OBJECTS) $(OBJS_J1)
	$(CC) -o $@ $(CFLAGS) $(OBJS_J1) $(OBJECTS) $(LDFLAGS)

$(TARGET_J2): $(OBJECTS) $(OBJS_J2)
	$(CC) -o $@ $(CFLAGS) $(OBJS_J2) $(OBJECTS) $(LDFLAGS)

$(MAIN_J1):
	$(CC) -o $@ -D_JACOBI1 $(CFLAGS) -c main.c 

$(MAIN_J2):
	$(CC) -o $@ -D_JACOBI2 $(CFLAGS) -c main.c 

clean:
	@/bin/rm -f core *.o *~

realclean: clean
	@/bin/rm -f $(TARGET_J1)  $(TARGET_J2)

clean_vtk:
	@/bin/rm -f *.vtk

# DO NOT DELETE

main_j1.o: main.c print.h jacobi1.h init_matrix.h
main_j2.o: main.c print.h jacobi2.h init_matrix.h
print.o: print.h
