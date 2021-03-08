#pragma once
#include "Instruction.h"

class MultInstruction : public Instruction{
 private:
  int operation;
  int directType;
 public:
  MultInstruction(/* args */);
  MultInstruction(std::string cad) { parse(cad); };
  ~MultInstruction();
  void parse(std::string);
  void execute(Context&);
  void disassemble();
};