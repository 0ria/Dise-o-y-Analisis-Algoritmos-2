#include "../include/ReadInstruction.h"

ReadInstruction::ReadInstruction(/* args */) {}

ReadInstruction::~ReadInstruction() {}

void ReadInstruction::parse(std::string instructionText) {
  std::istringstream iss(instructionText);
  std::string operAux;
  iss >> opcode >> operAux;
  if (operAux[0] == '=') {
    directType = inm;
    operation = int(operAux[1]);
  } else if (operAux[0] == '*') {
    directType = indir;
    operation = int(operAux[1]);
  } else {
    directType = dir;
    operation = std::stoi(operAux);
  }
}

void ReadInstruction::execute(Context& ctx) {
  if (directType == 1)
    ctx.mem -> storeVal(operation, ctx.in->getElementFromTape());
  else if (directType == 2)
    ctx.mem -> storeVal(ctx.mem ->getVal(operation), ctx.in->getElementFromTape());
  ctx.p++;
}

void ReadInstruction::disassemble() {
  std::cout << "OPCODE = " << opcode << ", DIRECCIONAMIENTO: ";
  if (directType == inm)
    std::cout << "INMEDIATO,";
  else if (directType == dir)
    std::cout << "DIRECTO, ";
  else if (directType == indir)
    std::cout << "INDIRECTO";
  std::cout << std::endl;
}