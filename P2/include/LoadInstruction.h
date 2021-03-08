#pragma once
#include "Instruction.h"

class LoadInstruction : public Instruction {
 private:
  int operation;
  int directType;
 public:
  LoadInstruction(/* args */);
  ~LoadInstruction();
  void parse(std::string);
  void execute(Context&);
  std::string disassemble();
};
