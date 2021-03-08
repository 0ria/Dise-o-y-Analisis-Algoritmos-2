#include "../include/Program.h"

Program::Program(/* args */) {}

Program::~Program() {}

Program::Program(std::ifstream& everyInstruction) {
  CleanProgram cleaner(everyInstruction);
  std::vector<std::string> uncommentedProgram = cleaner.getResultProg();
  tags = cleaner.getResultMap();

  for (int i = 0; i < uncommentedProgram.size(); i++) {
    instructions[i].parse(uncommentedProgram[i]);
  }
}
/*
void Program::showProgram() {
  std::cout << "El programa cargado del fichero es: \n"; 
  for (auto it : instructions) {
    std::cout << it;
  }
}
*/
void Program::showMap() {
  for (std::map<std::string, int>::const_iterator it = tags.begin(); it != tags.end(); it++) {
    std::cout << it -> first << " " << it -> second << "\n";
  }
}
