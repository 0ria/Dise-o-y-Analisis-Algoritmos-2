#include "../include/QuicksortP.h"

QuicksortP::QuicksortP(/* args */) {}

QuicksortP::~QuicksortP() {}

QuicksortP::QuicksortP(std::vector<int> unsortedNumbers, int l, int r) :
Problema::Problema(),
leftIndex(0),
rightIndex(r - l),
numbersVector() {
  for (int i = l; i <= r; i++)
    numbersVector.push_back(unsortedNumbers[i]);
}

bool QuicksortP::isCasoMinimo() {
  return (leftIndex == rightIndex);
}

std::pair<Problema*, Problema*> QuicksortP::descomponer() {
  std::pair<Problema*, Problema*> subProblemas;
  if (leftIndex < rightIndex) {
    int pivote = partition(numbersVector, leftIndex, rightIndex);
    subProblemas.first = new QuicksortP(numbersVector, leftIndex, pivote - 1);
    subProblemas.second = new QuicksortP(numbersVector, pivote, rightIndex);
    return subProblemas;
  }
}

int QuicksortP::partition(std::vector<int> v, int l, int r) {
  int pivot = v[r];
  int i = l - 1;
  for (int j = l; j <= r - 1; j++) {
    if (v[j] <= pivot) {
      i++;
      std::iter_swap(v.begin() + i, v.begin() + j);
    }
  }
  std::iter_swap(v.begin() + (i + 1), v.begin() + r);
  numbersVector = v;
  return (i + 1);
}

void QuicksortP::solver(Solucion* s) {
  ((QuicksortS*)s) -> setValor(numbersVector);
}