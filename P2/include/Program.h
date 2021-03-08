#pragma once
#include "Instruction.h"
#include "CleanProgram.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <map>
class Program
{
private:
  std::vector<Instruction> instructions;
  std::map<std::string, int> tags;
public:
  Program(/* args */);
  Program(std::ifstream&);
  ~Program();
  //void showProgram();
  void showMap();
};
