IDIR =../include
CXX=g++ -g -std=c++11 -o ram_sim
CFLAGS=-I$(IDIR) 

ODIR=../src
LDIR =../files

LIBS=-lm

_OBJ = CleanProgram.o BasicTape.o InputTape.o OutputTape.o Program.o Memory.o Instruction.o Cpu.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: ram_sim
ram_sim: ${OBJ} 
	$(CXX) $(CXXFLAGS) ${OBJ} 

	#rm -rf $(OBJS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ $(INCDIR)/*~