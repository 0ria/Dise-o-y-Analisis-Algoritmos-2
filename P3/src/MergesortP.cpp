#include "../include/mergesortP.h"

MergesortP::MergesortP(std::vector<int> v, int l, int r)
    : Problema::Problema(), leftIndex(0), rigthIndex(r - l), numbersVector() {
  for (int i = l; i <= r; i++) {
    //std::cout << " De la pos " << i << " pusheo elemento " << v[i] << "\n";
    numbersVector.push_back(v[i]);
  }
}

MergesortP::~MergesortP() {}

bool MergesortP::isCasoMinimo() { return (leftIndex == rigthIndex); }

std::pair<Problema*, Problema*> MergesortP::descomponer() {
  std::pair<Problema*, Problema*> subProblemas;
  // if (leftIndex < rigthIndex) {
  middleIndex = (rigthIndex - leftIndex) / 2;
  subProblemas.first = new MergesortP(numbersVector, leftIndex, middleIndex);
  subProblemas.second =
      new MergesortP(numbersVector, middleIndex + 1, rigthIndex);
  return subProblemas;
  //}
}

void MergesortP::solver(Solucion* s) {
  ((MergesortS*)s)->setValor(numbersVector, leftIndex, middleIndex, rigthIndex);
}