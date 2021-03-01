#include "../include/Memory.h"

Memory::Memory(/* args */) {
  registers.resize(8);
  std::fill(registers.begin(), registers.end(), 0);
}

Memory::~Memory() {}

int Memory::getVal(int pos) {
  return registers[pos];
}

void Memory::setVal(int val) {
  registers[0] = val;
}

void Memory::storeVal(int pos, int val) {
  registers[pos] = val;
}

void Memory::showMemoryRegisters(void) {
  for (int i = 0; i < registers.size(); i++) {
    std::cout << "R" << i << ": " << registers[i] << "\n";
  }
}