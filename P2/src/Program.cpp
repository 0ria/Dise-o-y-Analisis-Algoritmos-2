#include "../include/Program.h"

Program::Program(/* args */) {}

Program::~Program() {}

Program::Program(std::vector<Instruction*> allInstr, std::map<std::string, int>& tg) :
instructions(allInstr),
tags(tg) {

  
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

Instruction* Program::getInstruction(ProgramCounter& pc) {
  return instructions[pc.getDir()];
}