#include <iostream>
#include <istream>
#include <vector>
#include <string>

#include "../include/CleanProgram.h"
#include "../include/Cpu.h"

int main (int argc, char* argv[]) {
  std::ifstream inputTape, program;
  std::ofstream outputTape;
  int flag;

  program.open(argv[1]);
  inputTape.open(argv[2]);
  outputTape.open(argv[3]);
  flag = std::atoi(argv[4]);
  if ((!program.is_open()) || (!inputTape.is_open()))
    return 1;

  Cpu cpu(program, inputTape, outputTape, flag);
  cpu.executeProgram();
/*
  for (auto it : uncommentedProgram)
    std::cout << it << "\n";
*/
}