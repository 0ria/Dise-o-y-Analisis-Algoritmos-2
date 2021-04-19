#include "../include/LocalSearch.h"

LocalSearch::LocalSearch(/* args */) {}

LocalSearch::LocalSearch(std::vector<Machine>& actSol)
    : principalSolution(actSol) {}

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
            auxVect[i].getTasks().erase(auxVect[i].getTasks().begin() + j);
            variations.push_back(auxVect);
            auxVect = principalSolution;
          }
        }
      }
    }
  }
}

void LocalSearch::insertTasksSameMachine(void) {
  std::vector<Machine> auxVect = principalSolution;
  std::pair<int, int> auxPair;
  for (int i = 0; i < principalSolution.size(); i++) {
    for (int j = 0; j < principalSolution[i].getTasks().size(); j++) {
      for (int z = 0; z < principalSolution[i].getTasks().size(); z++) {
        if (j != z) {
          auxPair = auxVect[i].getTasks()[j];
          auxVect[i].getTasks().erase(auxVect[i].getTasks().begin() + j);
          auxVect[i].getTasks().insert(auxVect[i].getTasks().begin() + z,
                                       auxPair);
          variations.push_back(auxVect);
          auxVect = principalSolution;
        }
      }
    }
  }
}

void LocalSearch::greedySearch(int operativeMethod) {
  int minTct = getTotalTct(principalSolution);
  int currentTct = 0;
  bool foundBetterSolution = false;
  for (int i = 0; i < variations.size(); i++) {
    currentTct = getTotalTct(variations[i]);
    if (currentTct < minTct) {
      minTct = currentTct;
      principalSolution = variations[i];
      foundBetterSolution = true;
    }
  }
  if (foundBetterSolution)
    improveSolution(operativeMethod, 1, 1);  // El 1 del final borrar
}

void LocalSearch::anxiousSearch(int operativeMethod) {
  int minTct = getTotalTct(principalSolution);
  int currentTct = 0;
  bool foundBetterSolution = false;
  for (int i = 0; i < variations.size(); i++) {
    currentTct = getTotalTct(variations[i]);
    if (currentTct < minTct) {
      minTct = currentTct;
      principalSolution = variations[i];
      foundBetterSolution = true;
      break;
    }
  }
  if (foundBetterSolution)
    improveSolution(operativeMethod, 2, 1);  // El 1 del final borrar
}

int LocalSearch::getTotalTct(std::vector<Machine>& vec) {
  int tct;
  for (auto it : vec) tct += it.getTctTime();
  return tct;
}

void LocalSearch::improveSolution(int operativeMethod,
                                                  int exploreType,
                                                  int stopCondition) {
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

  switch (exploreType) {
    case 1:
      greedySearch(operativeMethod);
      break;
    case 2:
      anxiousSearch(operativeMethod);
      break;
  }
}