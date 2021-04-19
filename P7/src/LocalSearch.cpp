#include "../include/LocalSearch.h"

LocalSearch::LocalSearch(/* args */) {}

LocalSearch::~LocalSearch() {}

void LocalSearch::interTasksBetweenMachines(void) {
  std::vector<Machine> auxVect = principalSolution;
  for (int i = 0; i < principalSolution.size(); i++) {
    for (int j = 0; j < principalSolution[i].getTasks().size(); j++) {
      for (int z = i; z < principalSolution.size(); z++) {
        if (z != i) {
          for (int w = 0; w < principalSolution[z].getTasks().size(); w++) {
            std::swap(auxVect[i].getTasks()[j], auxVect[z].getTasks()[w]);
            variations.push_back(auxVect);
            auxVect = principalSolution;
          }
        }
      }
    }
  }
  std::cout << "\n|| " << variations.size() << " ||\n";
}

void LocalSearch::interTasksSameMachine(void) {
  std::vector<Machine> auxVect = principalSolution;
  for (int i = 0; i < principalSolution.size(); i++) {
    for (int j = 0; j < principalSolution[i].getTasks().size(); j++) {
      for (int z = j; z < principalSolution[i].getTasks().size(); z++) {
        if (j != z) {
          std::swap(auxVect[i].getTasks()[j], auxVect[i].getTasks()[z]);
          variations.push_back(auxVect);
          auxVect = principalSolution;
        }
      }
    }
  }
  std::cout << "\n|| " << variations.size() << " ||\n";
}

void LocalSearch::insertTasksBetweenMachines(void) {
  std::vector<Machine> auxVect = principalSolution;
  for (int i = 0; i < principalSolution.size(); i++) {
    for (int j = 0; j < principalSolution[i].getTasks().size(); j++) {
      for (int z = 0; z < principalSolution.size(); z++) {
        if (z != i) {
          for (int w = 0; w <= principalSolution[z].getTasks().size(); w++) {
            auxVect[z].getTasks().insert(auxVect[z].getTasks().begin() + w,
                                         auxVect[i].getTasks()[j]);
            variations.push_back(auxVect);
            auxVect = principalSolution;
          }
        }
      }
    }
  }
  std::cout << "\n|| " << variations.size() << " ||\n";
}

void LocalSearch::insertTasksSameMachine(void) {
  std::vector<Machine> auxVect = principalSolution;
  for (int i = 0; i < principalSolution.size(); i++) {
    for (int j = 0; j < principalSolution[i].getTasks().size(); j++) {
      for (int z = 0; z < principalSolution[i].getTasks().size(); z++) {
        if (j != z) {
          auxVect[i].getTasks().insert(auxVect[i].getTasks().begin() + z + 1, auxVect[i].getTasks()[j]);
          auxVect[i].getTasks().erase(auxVect[i].getTasks().begin() + j);
          variations.push_back(auxVect);
          auxVect = principalSolution;
        }
      }
    }
  }
  std::cout << "\n|| " << variations.size() << " ||\n";
}

std::vector<Machine> LocalSearch::improveSolution(
    std::vector<Machine> actualSol, int operativeMethod, int exploreType,
    int stopCondition) {
  principalSolution = actualSol;
  std::string s = std::to_string(exploreType) + std::to_string(stopCondition);
  int switchNumber = std::stoi(s);

  switch (operativeMethod) {
    case 1:
      interTasksBetweenMachines();
      break;
    case 2:
      interTasksSameMachine();
      break;
    case 3:
      insertTasksBetweenMachines();
      break;
    case 4:
      insertTasksSameMachine();
      break;
  }

  switch (switchNumber) {
    case 11:
      break;
    case 12:
      break;
    case 21:
      break;
    case 22:
      break;
  }
  return principalSolution;
}