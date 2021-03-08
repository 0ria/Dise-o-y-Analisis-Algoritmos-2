#pragma once
#include "Instruction.h"

class AddInstruction : public Instruction{
 private:
  int operation;
  int directType;
 public:
  AddInstruction(/* args */);
  AddInstruction(std::string cad) { parse(cad); };
  ~AddInstruction();
  void parse(std::string);
  void execute(Context&);
  void disassemble();
};