IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -pedantic
OLEV=-O3

ODIR=obj
LDIR =../lib

LIBS=-lm

_DEPS = %.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o my_reads.o allocations.o deallocations.o checks.o init.o calc_vel_den.o prints.o collide_stream.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(OLEV)

OceanBoltz: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(OLEV)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ OceanBoltz $(INCDIR)/*~ 
