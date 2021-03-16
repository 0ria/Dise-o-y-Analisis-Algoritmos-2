#include "../include/QuicksortS.h"
#include <algorithm>

QuicksortS::QuicksortS() : Solucion::Solucion() {

}

QuicksortS::~QuicksortS() {}

void QuicksortS::resolver() {
  std::cout << "[";
  for (auto it : numbersVector)
    std::cout << it << " ";
  std::cout << "]\n";
}

void QuicksortS::mezcla(std::pair<Solucion*, Solucion*> subSoluciones) {
  std::vector<int> v1 = (((QuicksortS*) subSoluciones.first)) -> numbersVector;
  std::vector<int> v2 = (((QuicksortS*) subSoluciones.second)) -> numbersVector;
  v1.insert(v1.end(), v2.begin(), v2.end());
  numbersVector = v1;
}

Solucion* QuicksortS::getInstance() {
  return new QuicksortS();
}

void QuicksortS::setValor(std::vector<int> v) {
  numbersVector = v;
}