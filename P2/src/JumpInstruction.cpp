#include "../include/JumpInstruction.h"

JumpInstruction::JumpInstruction(/* args */) {}

JumpInstruction::~JumpInstruction() {}

void JumpInstruction::parse(std::string instructionText) {
  std::istringstream iss(instructionText);
  std::string operAux;
  iss >> opcode >> operation;
}

void JumpInstruction::execute(Context& ctx) {
  ctx.p -> setDir(ctx.tags -> find(operation) -> second);
}

void JumpInstruction::disassemble() {
  std::cout << "OPCODE = " << opcode << ", DIRECCIONAMIENTO: ";
  if (directType == inm)
    std::cout << "INMEDIATO,";
  else if (directType == dir)
    std::cout << "DIRECTO, ";
  else if (directType == indir)
    std::cout << "INDIRECTO";
  std::cout << std::endl;
}