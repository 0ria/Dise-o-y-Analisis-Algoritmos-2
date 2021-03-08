#pragma once
#include "Instruction.h"

class HaltInstruction : public Instruction{
 private:
  std::string operation;
  int directType;
 public:
  HaltInstruction(/* args */);
  HaltInstruction(std::string cad) { parse(cad); };
  ~HaltInstruction();
  void parse(std::string);
  void execute(Context&);
  void disassemble();
};