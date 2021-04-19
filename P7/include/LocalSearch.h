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

 public:
  LocalSearch(/* args */);
  ~LocalSearch();
  std::vector<Machine> improveSolution(std::vector<Machine>, int, int, int);
  inline std::vector<Machine> getSolution() { return principalSolution; };
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