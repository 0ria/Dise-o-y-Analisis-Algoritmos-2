#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>

#include "LoadInstruction.h"
#include "StoreInstruction.h"
#include "AddInstruction.h"
#include "SubInstruction.h"
#include "MultInstruction.h"
#include "DivInstruction.h"
#include "ReadInstruction.h"
#include "WriteInstruction.h"
#include "JumpInstruction.h"
#include "JgtzInstruction.h"
#include "JzeroInstruction.h"
#include "HaltInstruction.h"


enum opcodes {
  LOAD,
  STORE,
  ADD,
  SUB,
  MULT,
  DIV,
  READ,
  WRITE,
  JUMP,
  JGTZ,
  JZERO,
  HALT
};

class CleanProgram
{
private:
  std::vector<Instruction*> finalProgram;
  std::map<std::string, int> tags;
  std::map<std::string, opcodes> mapOptions = {
    {"LOAD", LOAD}, {"STORE", STORE}, {"ADD", ADD},     {"SUB", SUB},
    {"MULT", MULT}, {"DIV", DIV},   {"READ", READ}, {"WRITE", WRITE},
    {"JUMP", JUMP},   {"JGTZ", JGTZ}, {"JZERO", JZERO}, {"HALT", HALT}};
public:
  CleanProgram(/* args */);
  CleanProgram(std::ifstream&);
  ~CleanProgram();
  std::vector<Instruction*> getResultProg();
  inline std::map<std::string, int> getResultMap() { return tags; };
};
