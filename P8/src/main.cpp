#include <fstream>
#include <vector>

#include "../include/Mdp.h"

int numberOfElements = 0;
int dimnesions = 0;
std::vector<Point> vectorInput;

void parseInput(std::ifstream& in) {
  std::string aux;
  in >> aux;
  numberOfElements = std::stoi(aux);
  in >> aux;
  dimnesions = std::stoi(aux);

  while (std::getline(in, aux)) {
    aux.erase( std::remove(aux.begin(), aux.end(), '\r'), aux.end() );
    try {
      if (aux == "")
        continue;
      else
        vectorInput.emplace_back(aux);
    } catch (std::invalid_argument) {
      continue;
    }
  }
}

int main(int argc, char* argv[]) {
  std::ifstream inFile;
  if (argc == 2) {
    inFile.open(argv[1]);
    parseInput(inFile);
  }
  Mdp mdpAlgorithm(numberOfElements, dimnesions, vectorInput);
  for (int i = 2; i <= 5; i++) {
    std::cout << "Número puntos en solución: " << i << "\n";
    mdpAlgorithm.greedy(i);
    mdpAlgorithm.printSol();
    std::cout << "\n-----------------\n\n";
  }
}