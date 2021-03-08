#pragma once
#include "Instruction.h"

class DivInstruction : public Instruction{
 private:
  int operation;
  int directType;
 public:
  DivInstruction(/* args */);
  DivInstruction(std::string cad) { parse(cad); };
  ~DivInstruction();
  void parse(std::string);
  void execute(Context&);
  void disassemble();
};