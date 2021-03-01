#include "../include/Program.h"

Program::Program(/* args */) {}

Program::~Program() {}

Program::Program(std::ifstream& everyInstruction) {
  CleanProgram cleaner(everyInstruction);
  std::vector<std::string> uncommentedProgram = cleaner.getResult();

  for (int i = 0; i < uncommentedProgram.size(); i++) {
    instructions.push_back(uncommentedProgram[i]);
  }
}

void Program::showProgram() {
  std::cout << "El programa cargado del fichero es: \n"; 
  for (auto it : instructions) {
    std::cout << it;
  }
}
