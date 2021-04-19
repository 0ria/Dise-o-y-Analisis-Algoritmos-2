#pragma once
#include <iostream>
#include <string>

#include "LocalSearch.h"
class Machines {
 private:
  int numberOfMachines;
  int numberOfTasks;
  std::vector<std::vector<int>> setupTimes;
  std::vector<int> processingTime;
  std::vector<int> remainingTasks;
  std::vector<Machine> machineVector;
  
  void resetTasks(void);

 public:
  Machines(/* args */);
  Machines(int, int, std::vector<std::vector<int>>&, std::vector<int>&);
  ~Machines();
  void printTimes(void);
  void greedy(void);
  //void betterGreedy(void);
  void grasp(void);
  int iterTime(void);
  std::vector<std::vector<int>> getBetterTime(int);
  bool minNotSelected(int, std::vector<std::vector<int>>&);
  void exploreLocal(int, int, int, int);
};