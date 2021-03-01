#pragma once
#include "Instruction.h"
#include "CleanProgram.h"
#include <vector>
#include <fstream>
#include <iostream>
class Program
{
private:
  std::vector<Instruction> instructions;
public:
  Program(/* args */);
  Program(std::ifstream&);
  ~Program();
  void showProgram();
};
