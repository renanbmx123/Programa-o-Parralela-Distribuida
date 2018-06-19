ENVLAD := $(shell command -v ladcomp 2> /dev/null)

.PHONY: clean, mrproper

IDIR = ./inc
SDIR = ./src

MPI = mpicc
LAD = ladcomp

LADFLAGS = -env mpicc

CC = gcc
CFLAGS =  -g -Wall -I$(IDIR)

_DEPSC = ordenation.c interleaving.c

DEPS = $(patsubst %,$(SDIR)/%,$(_DEPSC))


all: TPP2

#all: sequential parallel 
#sequential: $(SDIR)/sequential.c
#	$(CC) -o $@ $< $(SDIR)/bubblesort.c $(CFLAGS)

TPP2: $(SDIR)/TPP2.c
ifndef ENVLAD
	$(MPI) -o $@ $< $(DEPS) $(CFLAGS)
else
	$(LAD) $(LADFLAGS) -o $@ $< $(DEPS) $(CFLAGS)
endif



clean:
	rm -f *.o core.*

mrproper: clean
	rm -f TPP2

