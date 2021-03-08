#include "../include/InputTape.h"

InputTape::InputTape(/* args */){BasicTape();}

InputTape::InputTape(std::ifstream& in) {
  std::copy(std::istream_iterator<int>(in), std::istream_iterator<int>(),
            std::back_inserter(tape));
}

InputTape::~InputTape() {}

int InputTape::getElementFromTape(void) {
  actualPos++;
  return tape[actualPos - 1];
}