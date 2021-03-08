#pragma once
#include "Instruction.h"

class StoreInstruction : public Instruction {
 private:
  int operation;
  int directType;
 public:
  StoreInstruction(/* args */);
  StoreInstruction(std::string cad) { parse(cad); };
  ~StoreInstruction();
  void parse(std::string);
  void execute(Context&);
  void disassemble();
};