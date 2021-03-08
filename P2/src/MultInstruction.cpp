#include "../include/MultInstruction.h"

MultInstruction::MultInstruction(/* args */) {}

MultInstruction::~MultInstruction() {}

void MultInstruction::parse(std::string instructionText) {
  std::istringstream iss(instructionText);
  std::string operAux;
  iss >> opcode >> operAux;
  if (operAux[0] == '=') {
    directType = inm;
    operation = std::stoi(operAux.substr(1));
  } else if (operAux[0] == '*') {
    directType = indir;
    operation = std::stoi(operAux.substr(1));
  } else {
    directType = dir;
    operation = std::stoi(operAux);
  }
}

void MultInstruction::execute(Context& ctx) {
  if (directType == 0)
    ctx.mem -> setVal(ctx.mem -> getVal(0) * operation);
  else if (directType == 1)
    ctx.mem -> setVal(ctx.mem -> getVal(0) * ctx.mem -> getVal(operation));
  else if (directType == 2)
    ctx.mem -> setVal(ctx.mem -> getVal(0) * ctx.mem -> getVal(ctx.mem -> getVal(operation)));
  ctx.p -> iterate();
  
}

void MultInstruction::disassemble() {
  std::cout << "OPCODE = " << opcode << ", DIRECCIONAMIENTO: ";
  if (directType == inm)
    std::cout << "INMEDIATO,";
  else if (directType == dir)
    std::cout << "DIRECTO, ";
  else if (directType == indir)
    std::cout << "INDIRECTO";
  std::cout << std::endl;
}