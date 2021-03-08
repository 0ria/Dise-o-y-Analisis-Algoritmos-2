#pragma once
#include "Instruction.h"

class JzeroInstruction : public Instruction{
 private:
  std::string operation;
  int directType;
 public:
  JzeroInstruction(/* args */);
  JzeroInstruction(std::string cad) { parse(cad); };
  ~JzeroInstruction();
  void parse(std::string);
  void execute(Context&);
  void disassemble();
};