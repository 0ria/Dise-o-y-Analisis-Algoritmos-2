#include "../include/mergesortS.h"
#include <iostream>

MergesortS::MergesortS() : Solucion::Solucion() {

}

MergesortS::~MergesortS() {

}

void MergesortS::resolver() {
  std::cout << "[";
  for (auto it : numbersVector)
    std::cout << it << " ";
  std::cout << "]\n";
}

void MergesortS::mezcla(std::pair<Solucion*, Solucion*> subSoluciones) {
  std::vector<int> n1 = (((MergesortS*)subSoluciones.first)) -> numbersVector;
  std::vector<int> n2 = (((MergesortS*)subSoluciones.second)) -> numbersVector;
  merge(n1, n2);
}

void MergesortS::merge(std::vector<int> v1, std::vector<int> v2) {
  std::vector<int> aux1;
  int n1 = v1.size();
  int n2 = v2.size();

  int i = 0;
  int j = 0;
  int k = leftIndex;
  while (i < n1 && j < n2) {
    if (v1[i] <= v2[j]) {
      numbersVector.push_back(v1[i]);
      i++;
    }
    else {
      numbersVector.push_back(v2[j]);
      j++;
    }
  }
  while (i < n1) {
    numbersVector.push_back(v1[i]);;
    i++;
  }
  while (j < n2) {
    numbersVector.push_back(v2[j]);
    j++;
  }
}

Solucion* MergesortS::getInstance() {
  return new MergesortS();
}

void MergesortS::setValor(std::vector<int> v, int l, int m, int r) {
  numbersVector = v;
  leftIndex = l;
  middleIndex = m;
  rightIndex = r;
}