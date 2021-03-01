#include "../include/CleanProgram.h"

CleanProgram::CleanProgram(/* args */) {}

CleanProgram::CleanProgram(std::ifstream& input) {
  std::string cadena;
  int count = 0;
  int aux;
  while (getline(input, cadena)) {
    aux = cadena.find("#");
    if (cadena.size() == 0)
      continue;
    if (aux == std::string::npos) {
      finalProgram.push_back(cadena);
    }
  }
}


CleanProgram::~CleanProgram() {}

std::vector<std::string> CleanProgram::getResult() {
  return finalProgram;
}
