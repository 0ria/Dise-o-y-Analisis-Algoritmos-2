#include <iostream>
#include <istream>
#include <vector>
#include <string>

#include "../include/CleanProgram.h"
#include "../include/Cpu.h"

int main (int argc, char* argv[]) {
  std::ifstream inputTape, program;
  std::ofstream outputTape;
  int flag;

  if (argc != 5) {
    std::cout << "Error al introducir por línea de comandos, siga el formato: \n";
    std::cout << "./ram_sim programaEntrada.ram cintaEntrada.in cintaSalida.out flag\n";
    return 1;
  }

  program.open(argv[1]);
  inputTape.open(argv[2]);
  flag = std::atoi(argv[4]);
  if ((!program.is_open()) || (!inputTape.is_open())) {
    std::cout << "Error al abrir algun fichero\n";
    return 1;
  }

  CleanProgram cleaner(program);
  std::vector<Instruction*> allInstructions = cleaner.getResultProg();
  std::map<std::string, int> tags = cleaner.getResultMap();
  
  Cpu cpu(allInstructions, inputTape, argv[3], flag, tags);
  cpu.executeProgram();
/*
  for (auto it : uncommentedProgram)
    std::cout << it << "\n";
*/
}