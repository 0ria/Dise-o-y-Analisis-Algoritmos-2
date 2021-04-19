#include <fstream>
#include <sstream>

#include "../include/Machines.h"

int numberOfMachines = 0;
int numberOfTasks = 0;
std::vector<int> processingTime;
std::vector<std::vector<int> > setupTimes;

void parseInput(std::ifstream& in) {
  std::vector<int> auxVect;
  std::string aux;
  in >> aux >> aux;
  numberOfTasks = std::stoi(aux);
  in >> aux >> aux;
  numberOfMachines = std::stoi(aux);
  in >> aux;

  std::getline(in, aux);
  std::istringstream iss(aux);
  while (iss >> aux) {
    try {
      processingTime.push_back(std::stoi(aux));
    } catch (std::invalid_argument) {
      continue;
    }
  }

  std::getline(in, aux);
  while (std::getline(in, aux)) {
    std::istringstream iss(aux);
    while (iss >> aux) {
      auxVect.push_back(std::stoi(aux));
    }
    setupTimes.push_back(auxVect);
    auxVect.clear();
  }
}

int main(int argc, char* argv[]) {
  std::ifstream inFile;
  int operativeMethod = std::atoi(argv[2]);
  int exploreType = std::atoi(argv[3]);
  int stopCondition = std::atoi(argv[4]);
  int iterNum = std::atoi(argv[5]);

  if (argc == 6) {
    inFile.open(argv[1]);
    parseInput(inFile);
    int inputOption;
    std::cout << "Introduzca el tipo de algoritmo a ejecutar\n";
    std::cout << "1. Greedy\n";
    std::cout << "2. Another Greedy\n";
    std::cout << "3. GRASP\n";
    std::cout << "- ";
    std::cin >> inputOption;
    std::cout << std::endl;
    Machines machn(numberOfMachines, numberOfTasks, setupTimes, processingTime);

    switch (inputOption) {
      case 1:
        machn.greedy();
        break;
      case 2:
        machn.greedy();  // otro greedy
        break;
      case 3:
        machn.grasp();
        machn.exploreLocal(operativeMethod, exploreType, stopCondition,
                           iterNum);
        break;
      default:
        std::cout << "El número introducido no es válido\n";
        break;
    }

    /*
    Machines betterGreedyMachine(numberOfMachines, numberOfTasks, setupTimes,
                         processingTime);
    betterGreedyMachine.betterGreedy();

    Machines graspMachine(numberOfMachines, numberOfTasks, setupTimes,
                          processingTime);
    graspMachine.grasp();

    graspMachine.exploreLocal(operativeMethod, exploreType, stopCondition,
                              iterNum);
                              */

  } else {
    std::cout << "Error introduciendo datos\n";
  }
}