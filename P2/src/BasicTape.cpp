#include "../include/basicTape.h"

BasicTape::BasicTape() : 
actualPos(0) {
  
}

void BasicTape::showTape(void) {
  for (auto it : tape)
    std::cout << it << " ";
  std::cout << std::endl;
}

std::vector<int> BasicTape::getTape(void) {
  return tape;
}