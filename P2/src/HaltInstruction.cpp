#include "../include/HaltInstruction.h"

HaltInstruction::HaltInstruction(/* args */) {}

HaltInstruction::~HaltInstruction() {}

void HaltInstruction::parse(std::string instructionText) {
  std::istringstream iss(instructionText);
  std::string operAux;
  iss >> opcode;
}

void HaltInstruction::execute(Context& ctx) {
  throw('x');
}

void HaltInstruction::disassemble() {
  std::cout << "OPCODE = " << opcode << ", DIRECCIONAMIENTO: ";
}