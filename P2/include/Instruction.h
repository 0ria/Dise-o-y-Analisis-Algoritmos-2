#pragma once
#include <string>
#include <algorithm>
#include <iostream>
class Instruction
{
private:
  std::string tag;
  std::string instruction;
  std::string operation;
public:
  Instruction(/* args */);
  Instruction(std::string&);
  ~Instruction();
  friend std::ostream& operator<<(std::ostream& os, Instruction& ins) {
    os << ins.tag << ' ' << ins.instruction << ' ' << ins.operation << "\n";
    return os;
  }
};
