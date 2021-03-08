#pragma once
#include "Instruction.h"

class ReadInstruction : public Instruction{
 private:
  int operation;
  int directType;
 public:
  ReadInstruction(/* args */);
  ReadInstruction(std::string cad) { parse(cad); };
  ~ReadInstruction();
  void parse(std::string);
  void execute(Context&);
  void disassemble();
};