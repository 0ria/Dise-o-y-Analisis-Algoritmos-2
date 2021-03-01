#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <istream>

#include "InputTape.h"
#include "OutputTape.h"
#include "Program.h"
//#include "../include/Program.h"

class Cpu
{
private:
  //std::vector<int> registers;
  Program program;
  InputTape inTape;
  OutputTape outTape;
  int flagExecution;

public:
  Cpu(/* args */);
  Cpu(std::ifstream&, std::ifstream&, std::ofstream&, int);
  ~Cpu();
  void executeProgram();
};