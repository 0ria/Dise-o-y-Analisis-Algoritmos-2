#pragma once
#include "Instruction.h"

class SubInstruction : public Instruction{
 private:
  int operation;
  int directType;
 public:
  SubInstruction(/* args */);
  SubInstruction(std::string cad) { parse(cad); };
  ~SubInstruction();
  void parse(std::string);
  void execute(Context&);
  void disassemble();
};