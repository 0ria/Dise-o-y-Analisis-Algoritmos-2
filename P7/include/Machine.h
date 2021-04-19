#pragma once
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#include <cstdlib>
class Machine
{
private:
  std::vector<std::pair<int, int>> tasks;
  int tctTime;
  int totalTime;
public:
  Machine(/* args */);
  ~Machine();
  void addNewTask(std::pair<int, int>);
  void showInfo();
  void updateTct();
  inline int getTime(void) { return totalTime; };
  inline int getLastTask() { return (tasks.size() == 0) ? 0 : tasks.back().first; };
  inline int getTctTime () { return tctTime; };
  inline bool isEmpty() { return tasks.empty(); };
  inline std::vector<std::pair<int, int>>& getTasks() { return tasks; };
};