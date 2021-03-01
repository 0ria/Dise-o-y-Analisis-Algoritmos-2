#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <iostream>
class BasicTape
{
protected:
  std::vector<int> tape;
  int actualPos;
public:
  BasicTape(/* args */) {}
  ~BasicTape() {}
  void write(int);
  std::vector<int> getTape(void);
  int read(void);
  void showTape(void);
};
