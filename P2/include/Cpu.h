#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <istream>

#include "Program.h"
#include "Memory.h"
//#include "../include/Program.h"

class Cpu
{
private:
  //std::vector<int> registers;
  Program program;
  Memory memory;
  InputTape inTape;
  OutputTape outTape;
  ProgramCounter pc;
  int flagExecution;
  Context ctx;

public:
  Cpu(/* args */);
  Cpu(std::vector<Instruction*>, std::ifstream&, std::string, int, std::map<std::string,int>&);
  ~Cpu();
  void executeProgram();
  void step();
  bool keepRunning = true;
};