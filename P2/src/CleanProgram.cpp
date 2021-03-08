#include "../include/CleanProgram.h"

CleanProgram::CleanProgram(/* args */) {}

CleanProgram::CleanProgram(std::ifstream& input) {
  std::string cadena;
  std::string auxCadena;
  int count = 0;
  int aux;
  while (getline(input, cadena)) {
    aux = cadena.find("#");
    if (cadena.size() == 0) continue;
    if (aux == std::string::npos) {
      int auxTag;
      auxTag = cadena.find(":");
      if (auxTag == std::string::npos) {
        finalProgram.push_back(cadena);
      } else {
        auxCadena = cadena.substr(0, auxTag);
        cadena = cadena.substr(auxTag + 1);
        tags.insert(std::pair<std::string, int>(auxCadena, finalProgram.size() - 1));
        finalProgram.push_back(cadena);
      }
    }
  }
}

CleanProgram::~CleanProgram() {}

std::vector<std::string> CleanProgram::getResultProg() { return finalProgram; }
