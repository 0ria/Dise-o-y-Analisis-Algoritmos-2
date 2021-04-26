#include <fstream>
#include <sstream>

#include "../include/Machines.h"

int numberOfMachines = 0;
int numberOfTasks = 0;
std::vector<int> processingTime;
std::vector<std::vector<int> > setupTimes;

void parseInput(std::ifstream& in) {
  std::vector<int> auxVect;
  std::string aux;
  in >> aux >> aux;
  numberOfTasks = std::stoi(aux);
  in >> aux >> aux;
  numberOfMachines = std::stoi(aux);
  in >> aux;

  std::getline(in, aux);
  std::istringstream iss(aux);
  while (iss >> aux) {
    try {
      processingTime.push_back(std::stoi(aux));
    } catch (std::invalid_argument) {
      continue;
    }
  }

  std::getline(in, aux);
  while (std::getline(in, aux)) {
    std::istringstream iss(aux);
    while (iss >> aux) {
      auxVect.push_back(std::stoi(aux));
    }
    setupTimes.push_back(auxVect);
    auxVect.clear();
  }
}

int main(int argc, char* argv[]) {
  std::ifstream inFile;
  int operativeMethod = std::atoi(argv[2]);
  int exploreType = std::atoi(argv[3]);
  int stopCondition = std::atoi(argv[4]);
  int iterNum = std::atoi(argv[5]);

  if (argc == 7) {
    if (std::atoi(argv[6]) == 0) {
      inFile.open(argv[1]);
      parseInput(inFile);
      int inputOption;
      std::cout << "Introduzca el tipo de algoritmo a ejecutar\n";
      std::cout << "1. Greedy\n";
      std::cout << "2. Another Greedy\n";
      std::cout << "3. GRASP\n";
      std::cout << "4. VND\n";
      std::cout << "5. GVNS\n";
      std::cout << "- ";
      std::cin >> inputOption;
      std::cout << std::endl;
      Machines machn(numberOfMachines, numberOfTasks, setupTimes,
                     processingTime);

      switch (inputOption) {
        case 1:
          machn.greedy();
          machn.printTimes();
          break;
        case 2:
          machn.greedy();  // otro greedy
          machn.printTimes();
          break;
        case 3:
          machn.grasp();
          machn.exploreLocal(operativeMethod, exploreType, stopCondition,
                             iterNum);
          machn.printTimes();
          break;
        case 4:
          machn.grasp();
          machn.exploreLocal(operativeMethod, exploreType, stopCondition,
                             iterNum);
          machn.vnd(operativeMethod, exploreType, stopCondition, iterNum);
          machn.printTimes();
          break;
        case 5:
          machn.grasp();
          machn.exploreLocal(operativeMethod, exploreType, stopCondition,
                             iterNum);
          machn.gvns(operativeMethod, exploreType, stopCondition, iterNum);
          machn.printTimes();
          break;
        default:
          std::cout << "El número introducido no es válido\n";
          break;
      }

    } else {
      int operation = 1;
      int exploration = 1;
      int stopCon = 1;
      int iterations = 100;
      inFile.open(argv[1]);
      parseInput(inFile);
      std::cout << "----- MODO TRAZA -----\n\n";
      Machines machn(numberOfMachines, numberOfTasks, setupTimes,
                     processingTime);
      std::cout << "----- GREEDY ALGORITHM -----\n";
      auto start = std::chrono::steady_clock::now();
      machn.greedy();
      auto end = std::chrono::steady_clock::now();
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";

      std::cout << "----- GREEDY 2 ALGORITHM -----\n";
      start = std::chrono::steady_clock::now();
      machn.greedy2();
      end = std::chrono::steady_clock::now();
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";

      std::cout << "----- GRASP ALGORITHM : GREEDY INTRACHANGE -----\n";
      start = std::chrono::steady_clock::now();
      machn.grasp();
      end = std::chrono::steady_clock::now();
      machn.exploreLocal(1, 1, stopCon, iterations);
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";

      std::cout << "----- GRASP ALGORITHM : ANXIOUS INTRACHANGE -----\n";
      start = std::chrono::steady_clock::now();
      machn.grasp();
      machn.exploreLocal(1, 2, stopCon, iterations);
      end = std::chrono::steady_clock::now();
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";

      std::cout << "----- GRASP ALGORITHM : GREEDY INTERCHANGE -----\n";
      start = std::chrono::steady_clock::now();
      machn.grasp();
      machn.exploreLocal(2, 2, stopCon, iterations);
      end = std::chrono::steady_clock::now();
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";

      std::cout << "----- GRASP ALGORITHM : ANXIOUS INTERCHANGE -----\n";
      start = std::chrono::steady_clock::now();
      machn.grasp();
      machn.exploreLocal(2, 2, stopCon, iterations);
      end = std::chrono::steady_clock::now();
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";

      std::cout << "----- GRASP ALGORITHM : GREEDY INTRAINSERT -----\n";
      start = std::chrono::steady_clock::now();
      machn.grasp();
      machn.exploreLocal(3, 1, stopCon, iterations);
      end = std::chrono::steady_clock::now();
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";

      std::cout << "----- GRASP ALGORITHM : ANXIOUS INTRAINSERT -----\n";
      start = std::chrono::steady_clock::now();
      machn.grasp();
      machn.exploreLocal(3, 2, stopCon, iterations);
      end = std::chrono::steady_clock::now();
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";

      std::cout << "----- GRASP ALGORITHM : GREEDY INTERINSERT -----\n";
      start = std::chrono::steady_clock::now();
      machn.grasp();
      machn.exploreLocal(4, 1, stopCon, iterations);
      end = std::chrono::steady_clock::now();
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";

      std::cout << "----- GRASP ALGORITHM : ANXIOUS INTERINSERT -----\n";
      start = std::chrono::steady_clock::now();
      machn.grasp();
      machn.exploreLocal(4, 2, stopCon, iterations);
      end = std::chrono::steady_clock::now();
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";

      // VND
      std::cout << "----- VND ALGORITHM : GREEDY INTRACHANGE -----\n";
      start = std::chrono::steady_clock::now();
      machn.grasp();
      machn.exploreLocal(operativeMethod, exploreType, stopCondition, iterNum);
      machn.vnd(1, 1, stopCondition, iterNum);
      end = std::chrono::steady_clock::now();
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";

      std::cout << "----- VND ALGORITHM : ANXIOUS INTRACHANGE -----\n";
      start = std::chrono::steady_clock::now();
      machn.grasp();
      machn.exploreLocal(operativeMethod, exploreType, stopCondition, iterNum);
      machn.vnd(1, 2, 2, iterNum);
      end = std::chrono::steady_clock::now();
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";

      // GVNS
      std::cout << "----- GVNS ALGORITHM : GREEDY INTRACHANGE -----\n";
      start = std::chrono::steady_clock::now();
      machn.grasp();
      machn.exploreLocal(operativeMethod, exploreType, stopCondition, iterNum);
      machn.gvns(1, 1, stopCondition, iterNum);
      end = std::chrono::steady_clock::now();
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";

      std::cout << "----- GVNS ALGORITHM : ANXIOUS INTRACHANGE -----\n";
      start = std::chrono::steady_clock::now();
      machn.grasp();
      machn.exploreLocal(operativeMethod, exploreType, stopCondition, iterNum);
      machn.gvns(1, 2, stopCondition, iterNum);
      end = std::chrono::steady_clock::now();
      machn.printTimes();
      std::cout << "Elapsed time: "
                << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                         start)
                       .count()
                << "μs\n\n";
      std::cout << "-----------------------------------\n\n";
    }
  } else {
    std::cout << "Error introduciendo datos\n";
  }
}