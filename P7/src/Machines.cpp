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
}

Machines::~Machines() {}

bool Machines::minNotSelected(int pos,
                              std::vector<std::vector<int>>& minimums) {
  for (int i = 0; i < minimums.size(); i++) {
    if (minimums[i][1] == pos) return true;
  }
  return false;
}

void Machines::grasp() {
    while (remainingTasks.size() != 0) {
    std::vector<std::vector<int>> auxVect = getBetterTime(3);
    int index = rand() % auxVect.size();
    machineVector[auxVect[index][0]].addNewTask(
        std::make_pair(auxVect[index][1], auxVect[index][2]));

    remainingTasks.erase(std::remove(remainingTasks.begin(),
                                     remainingTasks.end(), auxVect[index][1]),
                         remainingTasks.end());
  }
  for (auto it : machineVector) it.showInfo();
}

void Machines::greedy() {
  while (remainingTasks.size() != 0) {
    std::vector<int> auxVect = getBetterTime(1)[0];
    machineVector[auxVect[0]].addNewTask(
        std::make_pair(auxVect[1], auxVect[2]));

    remainingTasks.erase(std::remove(remainingTasks.begin(),
                                     remainingTasks.end(), auxVect[1]),
                         remainingTasks.end());
  }
  for (auto it : machineVector) it.showInfo();
}

std::vector<std::vector<int>> Machines::getBetterTime(int k) {
  std::vector<std::vector<int>> auxVect;
  int currentTime;
  int currentIncrement;
  while (auxVect.size() != k) {
  int minTask = remainingTasks[0];
  int selectedMachine = 0;
  int minTime = setupTimes[0][remainingTasks[0]] + processingTime[remainingTasks[0] - 1];
  int minIncrement = minTime + machineVector[0].getTime();
    for (int i = 0; i < remainingTasks.size(); i++) {
      for (int j = 0; j < numberOfMachines; j++) {
        currentTime = (setupTimes[machineVector[j].getLastTask()][remainingTasks[i]] + processingTime[remainingTasks[i] - 1]);
        currentIncrement = currentTime + machineVector[j].getTime();
        if (currentIncrement < minIncrement && !minNotSelected(remainingTasks[i], auxVect)) {
          minTask = remainingTasks[i];
          minTime = currentTime;
          selectedMachine = j;
          minIncrement = currentIncrement;
        }
      }
    }
    auxVect.push_back(std::vector<int> {selectedMachine, minTask, minTime});
  }
  return auxVect;
}

void Machines::exploreLocal(int operativeMethod, int exploreType, int stopCondition) { 
  LocalSearch ls;
  ls.improveSolution(machineVector, operativeMethod, exploreType, stopCondition);
  machineVector = ls.getSolution();
}

/*
void Machines::betterGreedy() {
  for (int i = 0; i < numberOfMachines; i++) {
    machineVector[i].addNewTask(getBetterTime(0, 1));
  }

  while (remainingTasks.size() != 0) {
    int minimum = 99999;
    int selectedMachine = 0;
    for (int i = 0; i < numberOfMachines; i++) {
      if (machineVector[i].getTime() < minimum) {
        minimum = machineVector[i].getTime();
        selectedMachine = i;
      }
    }
    machineVector[selectedMachine].addNewTask(
        getBetterTime(machineVector[selectedMachine].getLastTask(), 1));
  }
  for (auto it : machineVector) it.showInfo();
}
*/
void Machines::printTimes(void) {
  for (auto it : processingTime) std::cout << it << " ";
  std::cout << "\n\n";

  for (auto it : setupTimes) {
    for (auto itt : it) {
      std::cout << itt << " ";
    }
    std::cout << std::endl;
  }
}