#include "../include/JzeroInstruction.h"

JzeroInstruction::JzeroInstruction(/* args */) {}

JzeroInstruction::~JzeroInstruction() {}

void JzeroInstruction::parse(std::string instructionText) {
  std::istringstream iss(instructionText);
  std::string operAux;
  iss >> opcode >> operation;
}

void JzeroInstruction::execute(Context& ctx) {
  if (ctx.mem -> getVal(0) == 0)
    ctx.p -> setDir(ctx.tags -> find(operation) -> second);
  else
    ctx.p++;
}

void JzeroInstruction::disassemble() {
  std::cout << "OPCODE = " << opcode << ", DIRECCIONAMIENTO: ";
  if (directType == inm)
    std::cout << "INMEDIATO,";
  else if (directType == dir)
    std::cout << "DIRECTO, ";
  else if (directType == indir)
    std::cout << "INDIRECTO";
  std::cout << std::endl;
}