#pragma once
#include "BasicTape.h"
#include <fstream>

class OutputTape : public BasicTape
{
private:
  //std::vector<int> tape;
  //int pos;
  std::string outFileName;
public:
  OutputTape(/* args */);
  OutputTape(std::string&);
  ~OutputTape();
  void write(int);
  void print(void);
};
