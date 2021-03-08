#include "../include/StoreInstruction.h"

StoreInstruction::StoreInstruction(/* args */) {}

StoreInstruction::~StoreInstruction() {}

void StoreInstruction::parse(std::string instructionText) {
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

void StoreInstruction::execute(Context& ctx) {
  if (directType == 0)
    std::cout << "Esto no tiene sentido\n Hacer algo";
  else if (directType == 1)
    ctx.mem->storeVal(operation, ctx.mem -> getVal(0));
  else if (directType == 2) {
    ctx.mem->storeVal(ctx.mem -> getVal(operation), ctx.mem -> getVal(0));
  }
  ctx.p -> iterate();
}

void StoreInstruction::disassemble() {
  std::cout << "OPCODE = " << opcode << ", DIRECCIONAMIENTO: ";
  if (directType == inm)
    std::cout << "INMEDIATO,";
  else if (directType == dir)
    std::cout << "DIRECTO, ";
  else if (directType == indir)
    std::cout << "INDIRECTO";
  std::cout << std::endl;
}