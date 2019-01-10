IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR) -g

ODIR=../build/obj
LDIR=../lib
TDIR=../test
BDIR=../build

LIBS=-lm -lncurses

_DEPS = screen.h nbnli.h game.h particle.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o screen.o nbnli.o particle.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

program: $(OBJ)
	$(CC) -o $(BDIR)/$@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(BDIR)/$(ODIR)/*.o *~ core $(INCDIR)/*~ $(BDIR)/program

.PHONY: run

run: ./program
	$(BDIR)/program ${ARGS}

.PHONY: test

test: ./program
	sh $(TDIR)/test.sh &>> $(TDIR)/program.log
