#pragma once
#include <iostream>
#include <string>
#include <chrono>

#include "LocalSearch.h"
class Machines {
 private:
  int numberOfMachines;
  int numberOfTasks;
  std::vector<std::vector<int>> setupTimes;
  std::vector<int> processingTime;
  std::vector<int> remainingTasks;
  std::vector<Machine> machineVector;
  LocalSearch ls;
  
  void resetTasks(void);
  int calculateTct(std::vector<Machine>&);
  int generateKMax(void);
  void generateRandomKPoints(int);
  bool isNotContained(std::vector<std::pair<std::pair<int, int>, std::pair<int, int>>>&, int, int);

 public:
  Machines(/* args */);
  Machines(int, int, std::vector<std::vector<int>>&, std::vector<int>&);
  ~Machines();
  void printTimes(void);
  void greedy(void);
  void greedy2(void);
  void grasp(void);
  void vnd(int, int, int, int);
  void gvns(int, int, int, int);
  int iterTime(void);
  std::vector<std::vector<int>> getBetterTime(int);
  std::vector<std::vector<int>> getBetterTime2(int);
  bool minNotSelected(int, std::vector<std::vector<int>>&);
  void exploreLocal(int, int, int, int);
};