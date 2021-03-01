#include "../include/Cpu.h"

Cpu::Cpu(/* args */) {}

Cpu::~Cpu() {}

Cpu::Cpu(std::ifstream& programInput, std::ifstream& inFile, std::ofstream& outFile, int flag) : 
program(programInput),
inTape(inFile),
outTape(outFile),
flagExecution(flag) {

}

void Cpu::executeProgram() {
  program.showProgram();
  std::cout << "\nEl contenido de la cinta de entrada es: \n";
  inTape.showTape();
  std::cout << "\nEl contenido de la cinta de salida es: \n";
  outTape.showTape();
}
