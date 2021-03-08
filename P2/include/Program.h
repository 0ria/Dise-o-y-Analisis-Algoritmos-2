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
  std::vector<Instruction*> instructions;
  std::map<std::string, int> tags;
public:
  Program(/* args */);
  Program(std::vector<Instruction*>, std::map<std::string, int>&);
  ~Program();
  //void showProgram();
  void showMap();
  inline std::map<std::string, int>* getTags() { return &tags; };
  Instruction* getInstruction(ProgramCounter&);
};
