#include "../include/LocalSearch.h"

LocalSearch::LocalSearch(/* args */) {}

LocalSearch::LocalSearch(std::vector<Machine>& actSol)
    : principalSolution(actSol) {}

LocalSearch::~LocalSearch() {}

// Algoritmo encargado de realizar todos los posibles intercambios de tareas entre distintas máquinas
void LocalSearch::interTasksBetweenMachines(void) {
  std::vector<Machine> auxVect = principalSolution;
  for (int i = 0; i < principalSolution.size(); i++) {
    for (int j = 0; j < principalSolution[i].getTasks().size(); j++) {
      for (int z = i; z < principalSolution.size(); z++) {
        if (z != i) {
          for (int w = 0; w < principalSolution[z].getTasks().size(); w++) {
            std::swap(auxVect[i].getTasks()[j], auxVect[z].getTasks()[w]);
            recalculateTime(auxVect, i, j);
            recalculateTime(auxVect, z, w);
            variations.push_back(auxVect);
            auxVect = principalSolution;
          }
        }
      }
    }
  }
}

// Algoritmo encargado de realizar todos los posibles intercambios de tareas entre una misma máquina
void LocalSearch::interTasksSameMachine(void) {
  std::vector<Machine> auxVect = principalSolution;
  for (int i = 0; i < principalSolution.size(); i++) {
    for (int j = 0; j < principalSolution[i].getTasks().size(); j++) {
      for (int z = j; z < principalSolution[i].getTasks().size(); z++) {
        if (j != z) {
          std::swap(auxVect[i].getTasks()[j], auxVect[i].getTasks()[z]);
          recalculateTime(auxVect, i, j);
          recalculateTime(auxVect, i, z);
          variations.push_back(auxVect);
          auxVect = principalSolution;
        }
      }
    }
  }
}

// Algoritmo encargado de realizar todas las posibles reinserciones de tareas entre distintas máquinas
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
            recalculateTime(auxVect, i, j);
            recalculateTime(auxVect, z, w);
            variations.push_back(auxVect);
            auxVect = principalSolution;
          }
        }
      }
    }
  }
}

// Algoritmo encargado de realizar todas las posibles reinserciones de tareas en una misma máquina
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
          recalculateTime(auxVect, i, j);
          recalculateTime(auxVect, i, z);
          variations.push_back(auxVect);
          auxVect = principalSolution;
        }
      }
    }
  }
}

// Método de exploración Greedy, si al final de recorrer todas las
// tareas encuentra una mejor solucion llama de nuevo a ImproveSulution
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
    improveSolution(operativeMethod, 1, 1);
}

// Método de exploración Ansioso, En el momento que encuentra una mejor
// tarea llama a ImproveLocal con esta nueva solución
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

// Calcula el tct total del un vector pasado
int LocalSearch::getTotalTct(std::vector<Machine>& vec) {
  int tct = 0;
  for (auto it : vec) {
    it.updateTct();
    tct += it.getTctTime();
  }
  return tct;
}

// Método el cual realiza una mejora local con un tipo de exploración
void LocalSearch::improveSolution(int operativeMethod, int exploreType,
                                  int stopCondition) {
  variations.clear();
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

// Método que setea los tiempos de procesado y de setup para poder recalcular el 
// tiempo al cambiar tareas
void LocalSearch::setVectTimes(std::vector<std::vector<int>> st,
                               std::vector<int> pt) {
  setupTimes = st;
  processingTime = pt;
}

// Método que recalcula el tiempo de las tareas al cambiarlas de posiciones
void LocalSearch::recalculateTime(std::vector<Machine>& machineArray,
                                  int machineIndex, int taskIndex) {
  std::vector<std::pair<int, int>>& machine =
      machineArray[machineIndex].getTasks();
  if (taskIndex == 0) {
    machine[taskIndex].second = setupTimes[0][machine[taskIndex].first] +
                                processingTime[machine[taskIndex].first - 1];
  } else {
    machine[taskIndex].second =
        setupTimes[machine[taskIndex - 1].first][machine[taskIndex].first] +
        processingTime[machine[taskIndex].first - 1];
  }
  if (taskIndex < machine.size() - 1) {
    machine[taskIndex + 1].second =
        setupTimes[machine[taskIndex].first][machine[taskIndex + 1].first] +
        processingTime[machine[taskIndex + 1].first - 1];
  }
}