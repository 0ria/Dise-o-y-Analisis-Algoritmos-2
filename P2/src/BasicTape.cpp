#include "../include/basicTape.h"

BasicTape::BasicTape() : 
actualPos(0) {

}

void BasicTape::showTape(std::ostream& os) {
  for (auto it : tape)
    os << it << " ";
  os << std::endl;
}

std::vector<int> BasicTape::getTape(void) {
  return tape;
}