#include "../include/OutputTape.h"

OutputTape::OutputTape(/* args */) {}

OutputTape::~OutputTape() {}

OutputTape::OutputTape(std::ofstream& out) {
  tape.resize(8);
  std::fill(tape.begin(), tape.end(), 0);
}

void OutputTape::write(int num) {
  tape.push_back(num);
}
