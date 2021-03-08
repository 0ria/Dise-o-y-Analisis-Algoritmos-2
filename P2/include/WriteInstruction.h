#pragma once
#include "Instruction.h"

class WriteInstruction : public Instruction{
 private:
  int operation;
  int directType;
 public:
  WriteInstruction(/* args */);
  WriteInstruction(std::string cad) { parse(cad); };
  ~WriteInstruction();
  void parse(std::string);
  void execute(Context&);
  void disassemble();
};