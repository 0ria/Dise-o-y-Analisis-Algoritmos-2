#include "../include/OutputTape.h"

OutputTape::OutputTape(/* args */) {BasicTape();}

OutputTape::~OutputTape() {}

OutputTape::OutputTape(std::string& out) : 
outFileName(out) {

}

void OutputTape::write(int num) { tape.push_back(num); }

void OutputTape::print() { 
  std::ofstream outFile;
  outFile.open(outFileName);
  showTape(outFile);
  //outFile.open(showTape(std::cout)); 
}