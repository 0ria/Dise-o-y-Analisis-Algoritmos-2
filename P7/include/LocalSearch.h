#include <vector>

#include "Machine.h"
class LocalSearch {
 private:
  std::vector<Machine> principalSolution;
  std::vector<std::vector<Machine>> variations;

  void interTasksBetweenMachines(void);
  void interTasksSameMachine(void);
  void insertTasksBetweenMachines(void);
  void insertTasksSameMachine(void);

  void greedySearch(int);
  void anxiousSearch(int);


 public:
  LocalSearch(/* args */);
  LocalSearch(std::vector<Machine>&);
  ~LocalSearch();
  void improveSolution(int, int, int);
  inline std::vector<Machine> getSolution() { return principalSolution; };
  inline void setMachineVector(std::vector<Machine>& v) {principalSolution = v; }; 
  int getTotalTct(std::vector<Machine>&);
};

// Método multiarranque
// 1. intercambio de tareas entre máquinas
// 2. intercambio de tareas en misma máquina
// 3. re-inserción de una tarea en otra posición de otra máquina
// 4. re-inserción de una tarea en misma máquina

// Tipo de búsqueda
// 1. Greedy
// 2. Ansiosa

// Condición de parada
// 1. Por número de iter
// 2. Por número de iter sin mejora