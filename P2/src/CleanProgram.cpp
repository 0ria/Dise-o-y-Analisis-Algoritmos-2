#include "../include/CleanProgram.h"

CleanProgram::CleanProgram(/* args */) {}

CleanProgram::CleanProgram(std::ifstream& input) {
  std::string cadena;
  std::string auxCadena;
  std::string opcode;
  std::string operation;
  int count = 0;
  int aux;
  while (getline(input, cadena)) {
    aux = cadena.find("#");
    if (cadena.size() == 0) continue;
    if (aux == std::string::npos) {
      cadena.erase(std::remove(cadena.begin(), cadena.end(), '\t'),
                   cadena.end());
      cadena.erase(std::remove(cadena.begin(), cadena.end(), '\r'),
                   cadena.end());
      int auxTag;
      auxTag = cadena.find(":");
      if (auxTag != std::string::npos) {
        auxCadena = cadena.substr(0, auxTag);
        cadena = cadena.substr(auxTag + 1);
        tags.insert(
            std::pair<std::string, int>(auxCadena, finalProgram.size() - 1));
        // finalProgram.push_back(cadena);
      }
      std::transform(cadena.begin(), cadena.end(), cadena.begin(), ::toupper);
      std::istringstream iss(cadena);
      iss >> opcode >> operation;
      switch (mapOptions.find(opcode)->second) {
        case LOAD:
          finalProgram.push_back(new LoadInstruction(cadena));
          break;
        case STORE:
          finalProgram.push_back(new StoreInstruction(cadena));
          break;
        case ADD:
          finalProgram.push_back(new AddInstruction(cadena));
          break;
        case SUB:
          finalProgram.push_back(new SubInstruction(cadena));
          break;
        case MULT:
          finalProgram.push_back(new MultInstruction(cadena));
          break;
        case DIV:
          finalProgram.push_back(new DivInstruction(cadena));
          break;
        case READ:
          finalProgram.push_back(new ReadInstruction(cadena));
          break;
        case WRITE:
          finalProgram.push_back(new WriteInstruction(cadena));
          break;
        case JUMP:
          finalProgram.push_back(new JumpInstruction(cadena));
          break;
        case JGTZ:
          finalProgram.push_back(new JgtzInstruction(cadena));
          break;
        case JZERO:
          finalProgram.push_back(new JzeroInstruction(cadena));
          break;
        case HALT:
          //finalProgram.push_back(new HaltInstruction(cadena));
          break;
      }
    }
  }
}

CleanProgram::~CleanProgram() {}

std::vector<Instruction*> CleanProgram::getResultProg() { return finalProgram; }
