#include "../include/InputTape.h"

InputTape::InputTape(/* args */) {}

InputTape::InputTape(std::ifstream& in) {
  std::copy(
    std::istream_iterator<int>(in),
    std::istream_iterator<int>(),
    std::back_inserter(tape));
}

InputTape::~InputTape() {}
