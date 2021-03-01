IDIR =../include
CXX=g++ -g -std=c++11 -o main
CFLAGS=-I$(IDIR) -g

ODIR=../src
#LDIR =../files

LIBS=-lm

_OBJ = matrixClass.o columnMatrix.o rowMatrix.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main
main: ${OBJ} 
			$(CXX) $(CXXFLAGS) ${OBJ}

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~