#pragma once
#include "basicTape.h"

class InputTape : public BasicTape{
 private:
  //int pos;
  //std::vector<int> tape;
  //int actualPos;
 public:
  InputTape(/* args */);
  InputTape(std::ifstream&);
  ~InputTape();
  int getElementFromTape();
};