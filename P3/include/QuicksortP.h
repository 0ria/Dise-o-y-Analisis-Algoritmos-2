#ifndef QUICKSORTP_P_
#define QUICKSORTP_P_

#include "../framework/Problema.h"
#include "QuicksortS.h"
#include <vector>
#include <algorithm>

class QuicksortP : public Problema {
 private:
  std::vector<int> numbersVector;
  int leftIndex;
  int rightIndex;
 public:
  QuicksortP(/* args */);
  QuicksortP(std::vector<int>, int, int);
  ~QuicksortP();

  bool isCasoMinimo();
  std::pair<Problema*, Problema*> descomponer();
  void solver(Solucion*);
  int partition(std::vector<int>, int, int);
};

#endif /* QUICKSORTP_P_ */