#pragma once
#include "Instruction.h"

class JgtzInstruction : public Instruction{
 private:
  std::string operation;
  int directType;
 public:
  JgtzInstruction(/* args */);
  JgtzInstruction(std::string cad) { parse(cad); };
  ~JgtzInstruction();
  void parse(std::string);
  void execute(Context&);
  void disassemble();
};