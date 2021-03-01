#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
class Memory
{
private:
  std::vector<int> registers;
public:
  Memory(/* args */);
  ~Memory();
  int getVal(int);
  void setVal(int);
  void storeVal(int, int);
  void showMemoryRegisters(void);
};