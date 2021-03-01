#pragma once
#include <fstream>
#include <vector>
#include <string>

class CleanProgram
{
private:
  std::vector<std::string> finalProgram;
public:
  CleanProgram(/* args */);
  CleanProgram(std::ifstream&);
  ~CleanProgram();
  std::vector<std::string> getResult();
};
