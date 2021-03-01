#include "../include/OutputTape.h"

OutputTape::OutputTape(/* args */) {}

OutputTape::~OutputTape() {}

OutputTape::OutputTape(std::ofstream& out) {
  tape.resize(8);
  std::fill(tape.begin(), tape.end(), 0);
}
