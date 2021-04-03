IDIR =../include
CXX=g++ -std=c++11 -g -o LCS
CFLAGS=-I$(IDIR) 

ODIR=../src
LDIR =../files

LIBS=-lm

_OBJ = Lcs.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: lcs
lcs: ${OBJ} 
	$(CXX) $(CXXFLAGS) ${OBJ} 

	#rm -rf $(OBJS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~