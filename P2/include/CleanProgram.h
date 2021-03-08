#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
class CleanProgram
{
private:
  std::vector<std::string> finalProgram;
  std::map<std::string, int> tags;
public:
  CleanProgram(/* args */);
  CleanProgram(std::ifstream&);
  ~CleanProgram();
  std::vector<std::string> getResultProg();
  inline std::map<std::string, int> getResultMap() { return tags; };
};
