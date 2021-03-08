#include "../include/ProgramCounter.h"

ProgramCounter::ProgramCounter(/* args */) {}

ProgramCounter::~ProgramCounter() {}

void ProgramCounter::operator=(int number) {
  setDir(number);
}

void ProgramCounter::operator++(int number) {
  nextDir += 1;
}

std::ostream& ProgramCounter::operator<<(std::ostream& os) {
  os << nextDir;
  return os;
}