#include "../include/Machines.h"

Machines::Machines(/* args */) {}

Machines::Machines(int totalMach, int totalTask,
                   std::vector<std::vector<int>>& setupTim,
                   std::vector<int>& processTime)
    : numberOfMachines(totalMach),
      numberOfTasks(totalTask),
      setupTimes(setupTim),
      processingTime(processTime) {
  machineVector.resize(numberOfMachines);
  for (int i = 1; i <= numberOfTasks; i++) remainingTasks.push_back(i);
  ls.setVectTimes(setupTimes, processingTime);
}

Machines::~Machines() {}

// Método que resetea los vectores cada vez que se llama
void Machines::resetTasks() {
  remainingTasks.clear();
  machineVector.clear();
  machineVector.resize(numberOfMachines);
  for (int i = 1; i <= numberOfTasks; i++) remainingTasks.push_back(i);
}

// Método usado para ver si un mínimo ya ha sido seleccionado
bool Machines::minNotSelected(int pos,
                              std::vector<std::vector<int>>& minimums) {
  for (int i = 0; i < minimums.size(); i++) {
    if (minimums[i][1] == pos) return true;
  }
  return false;
}

// Método constructivo del grasp
void Machines::grasp() {
  resetTasks();
  // resetTct();
  while (remainingTasks.size() != 0) {
    std::vector<std::vector<int>> auxVect = getBetterTime(2);
    int index = rand() % auxVect.size();
    machineVector[auxVect[index][0]].addNewTask(
        std::make_pair(auxVect[index][1], auxVect[index][2]));

    remainingTasks.erase(std::remove(remainingTasks.begin(),
                                     remainingTasks.end(), auxVect[index][1]),
                         remainingTasks.end());
  }
}

// Método constructivo del Greedy
void Machines::greedy() {
  resetTasks();
  while (remainingTasks.size() != 0) {
    std::vector<int> auxVect = getBetterTime(1)[0];
    machineVector[auxVect[0]].addNewTask(
        std::make_pair(auxVect[1], auxVect[2]));

    remainingTasks.erase(
        std::remove(remainingTasks.begin(), remainingTasks.end(), auxVect[1]),
        remainingTasks.end());
  }
}

// Segundo algoritmo implementado para el Greedy
void Machines::greedy2() {
  resetTasks();
  while (remainingTasks.size() != 0) {
    std::vector<int> auxVect = getBetterTime2(1)[0];
    machineVector[auxVect[0]].addNewTask(
        std::make_pair(auxVect[1], auxVect[2]));

    remainingTasks.erase(
        std::remove(remainingTasks.begin(), remainingTasks.end(), auxVect[1]),
        remainingTasks.end());
  }
}

// Método el cual se queda con las k mejores tareas que quedan aun por asignar
std::vector<std::vector<int>> Machines::getBetterTime(int k) {
  std::vector<std::vector<int>> auxVect;
  int currentTime;
  int currentIncrement;
  while (auxVect.size() != k) {
    int minTask = remainingTasks[0];
    int selectedMachine = 0;
    int minTime =
        setupTimes[machineVector[0].getLastTask()][remainingTasks[0]] +
        processingTime[remainingTasks[0] - 1];
    int minIncrement = minTime + machineVector[0].getTime();
    for (int i = 0; i < remainingTasks.size(); i++) {
      for (int j = 0; j < numberOfMachines; j++) {
        currentTime =
            (setupTimes[machineVector[j].getLastTask()][remainingTasks[i]] +
             processingTime[remainingTasks[i] - 1]);
        currentIncrement = currentTime + machineVector[j].getTime();
        if (currentIncrement < minIncrement &&
            !minNotSelected(remainingTasks[i], auxVect)) {
          minTask = remainingTasks[i];
          minTime = currentTime;
          selectedMachine = j;
          minIncrement = currentIncrement;
        }
      }
    }
    auxVect.push_back(std::vector<int>{selectedMachine, minTask, minTime});
  }
  return auxVect;
}

// Método el cual se queda con las k mejores tareas que quedan aun por asignar para el Greedy2
std::vector<std::vector<int>> Machines::getBetterTime2(int k) {
  std::vector<std::vector<int>> auxVect;
  int currentTime;
  while (auxVect.size() != k) {
    int minTask = remainingTasks[0];
    int selectedMachine = 0;
    int minTime =
        setupTimes[machineVector[0].getLastTask()][remainingTasks[0]] +
        processingTime[remainingTasks[0] - 1];
    for (int i = 0; i < remainingTasks.size(); i++) {
      for (int j = 0; j < numberOfMachines; j++) {
        currentTime =
            (setupTimes[machineVector[j].getLastTask()][remainingTasks[i]] +
             processingTime[remainingTasks[i] - 1]);
        if (currentTime < minTime &&
            !minNotSelected(remainingTasks[i], auxVect)) {
          minTask = remainingTasks[i];
          minTime = currentTime;
          selectedMachine = j;
        }
      }
    }
    auxVect.push_back(std::vector<int>{selectedMachine, minTask, minTime});
  }
  return auxVect;
}

// Método que calcula el tct de un vector de máquinas pasado por referencia
int Machines::calculateTct(std::vector<Machine>& vm) {
  int tct = 0;
  for (auto it : vm) {
    it.updateTct();
    tct += it.getTctTime();
  }
  return tct;
}

// Método que calcula minimos locales haciendo uso del improveSolution de la clase localSearch
void Machines::vnd(int operativeMethod, int exploreType, int stopCondition,
                   int iterationsNumber) {
  ls.setMachineVector(machineVector);
  int actualOperativeMethod = 1;
  bool breakLoop = false;
  while (!breakLoop) {
    std::vector<Machine> actualSolution = machineVector;
    int actualTct = calculateTct(actualSolution);
    ls.improveSolution(actualOperativeMethod, exploreType, stopCondition);
    machineVector = ls.getSolution();
    if (actualTct <= calculateTct(machineVector)) {
      machineVector = actualSolution;
      if (actualOperativeMethod < 4)
        actualOperativeMethod++;
      else
        breakLoop = true;
    } else {
      actualOperativeMethod = 1;
    }
  }
}

// Método que genera la k max para el correcto funcionamiento del gvns, como máximo es 5
int Machines::generateKMax() {
  int minimum = machineVector[0].getTasks().size();
  for (int i = 0; i < machineVector.size(); i++)
    if (machineVector[i].getTasks().size() < minimum)
      minimum = machineVector[i].getTasks().size();
  return std::min(minimum, 5);
}

// Método que comprueba si el procesp generado por generateRandomKPoints no ha sido cambiado ya de máquina
bool Machines::isNotContained(
    std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>& vec,
    int machine, int task) {
  for (int i = 0; i < vec.size(); i++) {
    if (((machine == vec[i].first.first) && (task == vec[i].first.second)) ||
        ((machine == vec[i].second.first) && (task == vec[i].second.second)))
      return true;
  }
  return false;
}

// Método que genera k saltos (intercambios) y los realiza dentro del vector de máquinas 
void Machines::generateRandomKPoints(int k) {
  int i = 0;
  std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>> changesDone;
  while (i != k) {
    int randomMachineOne = rand() % machineVector.size();
    int randomMachineTwo = rand() % machineVector.size();
    // std::cout << randomMachineOne << " - " << randomMachineTwo << "\n";

    int randomPosOne =
        rand() % machineVector[randomMachineOne].getTasks().size();
    int randomPosTwo =
        rand() % machineVector[randomMachineTwo].getTasks().size();

    if ((changesDone.empty() && randomMachineOne != randomMachineTwo) ||
        (randomMachineOne != randomMachineTwo &&
         !isNotContained(changesDone, randomMachineOne, randomPosOne) &&
         !isNotContained(changesDone, randomMachineTwo, randomPosTwo))) {
      std::swap(machineVector[randomMachineOne].getTasks()[randomPosOne],
                machineVector[randomMachineTwo].getTasks()[randomPosTwo]);
      ls.recalculateTime(machineVector, randomMachineOne, randomPosOne);
      ls.recalculateTime(machineVector, randomMachineTwo, randomPosTwo);
      i++;
    }
  }
}

// Método el cual haciendo uso de los saltos y del vnd trata de encontrar minimos globales
void Machines::gvns(int operativeMethod, int exploreType, int stopCondition,
                    int iterationsNumber) {
  for (int i = 0; i < iterationsNumber; i++) {
    // std::cout << "i: " << i << "\n";
    std::vector<Machine> actualSolution = machineVector;
    int actualTct;
    int k = 1;
    int kmax = generateKMax();
    while (k <= kmax) {
      generateRandomKPoints(k);
      // std::cout << "Entrando en vnd\n";
      vnd(operativeMethod, exploreType, stopCondition, iterationsNumber);
      // actualTct = calculateTct(actualSolution);
      int newTct = calculateTct(machineVector);
      if (actualTct > newTct) {
        actualTct = newTct;
        k = 1;
      } else {
        machineVector = actualSolution;
        k++;
      }
    }
  }
}

// Método el cual se usa para explorar vecinas e ir mejorando una solución inicial
// Hace uso de improveSolution de la clase LocalSearch, el case 1 es Greedy y el case 2 Ansioso
void Machines::exploreLocal(int operativeMethod, int exploreType,
                            int stopCondition, int iterationsNumber) {
  // LocalSearch ls;
  switch (stopCondition) {
    case 1:
      for (int i = 0; i < iterationsNumber; i++) {
        grasp();
        ls.setMachineVector(machineVector);
        ls.improveSolution(operativeMethod, exploreType, stopCondition);
      }
      machineVector = ls.getSolution();
      break;
    case 2:
      int actualIterations = 0;
      bool firstIteration = true;
      int minTct;
      while (actualIterations != iterationsNumber) {
        grasp();
        ls.setMachineVector(machineVector);
        ls.improveSolution(operativeMethod, exploreType, stopCondition);
        machineVector = ls.getSolution();
        if (firstIteration) {
          minTct = ls.getTotalTct(machineVector);
          firstIteration = false;
        }
        if (ls.getTotalTct(machineVector) < minTct) {
          minTct = ls.getTotalTct(machineVector);
          actualIterations = 0;
        } else
          actualIterations++;
      }
      break;
  }
}

// Método que printea por consola informacion de las máquinas y el tct total
void Machines::printTimes(void) {
  for (auto it : machineVector) {
    it.showInfo();
  }
  std::cout << "Total TCT = " << calculateTct(machineVector) << "\n";
}