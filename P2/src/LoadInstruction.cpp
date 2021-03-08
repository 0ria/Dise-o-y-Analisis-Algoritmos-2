#include "../include/LoadInstruction.h"

LoadInstruction::LoadInstruction(/* args */) {}

LoadInstruction::~LoadInstruction() {}

void LoadInstruction::parse(std::string instructionText) {
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

  void LoadInstruction::execute(Context & ctx) {
    if (directType == 0) 
      ctx.mem -> setVal(operation);
    else if (directType == 1)
      ctx.mem -> setVal(ctx.mem -> getVal(operation));
    else if (directType == 2)
      ctx.mem -> setVal(ctx.mem -> getVal(ctx.mem -> getVal(operation)));
  }