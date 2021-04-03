#include "../include/Lcs.h"

int main (int argc, char *argv[]) {
  if (argc != 3) {
    std::cout << "Error, introduzca dos cadenas en la entrada por línea de comandos\n";
    std::cout << "./lcs cadena1 cadena2\n";
  }
  else {
    std::cout << std::endl;
    std::string firstSequence = argv[1];
    std::string secondSequence = argv[2];
    Lcs longesCommonSubsequenceObject(firstSequence, secondSequence);
    longesCommonSubsequenceObject.solve();
    longesCommonSubsequenceObject.getResults();
  }
}