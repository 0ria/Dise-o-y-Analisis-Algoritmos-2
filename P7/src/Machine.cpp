#include "../include/Machine.h"

Machine::Machine(/* args */) : totalTime(0),
tctTime(0) {}

Machine::~Machine() {}

// Método que renueva el tct de una máquina
void Machine::updateTct(void) {
  tctTime = 0;
  for (int i = 0; i < tasks.size(); i++) {
    tctTime += tasks[i].second * (tasks.size() - i);
  }
}

// Método que añade una nueva tarea a una máquina
void Machine::addNewTask(std::pair<int, int> taskNum) {
  totalTime += taskNum.second;
  tasks.push_back(taskNum);
}

// Método que printea información de una máquina
void Machine::showInfo(void) {
  for (auto it: tasks) 
    std::cout << "[" << it.first << ", " << it.second << "] ";
  //std::cout << "\n";
  std::cout << "\nTotal time: " << totalTime << "\n";
  updateTct();
  std::cout << "Total tct time: " << tctTime << "\n\n";
}