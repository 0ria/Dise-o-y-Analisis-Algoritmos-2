#pragma once
#include "Memory.h"
#include "InputTape.h"
#include "OutputTape.h"
#include "ProgramCounter.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>

enum DIRECT {inm, dir, indir};

struct Context {
  Memory* mem;
  InputTape* in;
  OutputTape* out;
  ProgramCounter* p;
  std::map<std::string, int>* tags;
};

class Instruction
{
protected:
  std::string opcode;
public:
  Instruction(/* args */);
  virtual ~Instruction() = default;
  virtual void parse(std::string instructionText) = 0;
  virtual void execute(Context&) = 0;
  virtual void disassemble() = 0;
};


/*
class Instruction
{
private:
  std::string tag;
  std::string instruction;
  std::string operation;
public:
  Instruction();
  Instruction(std::string&);
  ~Instruction();
  friend std::ostream& operator<<(std::ostream& os, Instruction& ins) {
    os << ins.tag << ' ' << ins.instruction << ' ' << ins.operation << "\n";
    return os;
  }
};
*/
