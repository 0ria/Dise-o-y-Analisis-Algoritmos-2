#pragma once
#include "Instruction.h"

class JumpInstruction : public Instruction{
 private:
  std::string operation;
  int directType;
 public:
  JumpInstruction(/* args */);
  JumpInstruction(std::string cad) { parse(cad); };
  ~JumpInstruction();
  void parse(std::string);
  void execute(Context&);
  void disassemble();
};