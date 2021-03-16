#ifndef MERGESORTP_P_
#define MERGESORTP_P_

#include "../framework/Problema.h"
#include "../include/mergesortS.h"

class MergesortP : public Problema {
  public:
    MergesortP(std::vector<int>, int, int);
    virtual ~MergesortP();

    bool isCasoMinimo();
    std::pair<Problema*, Problema*> descomponer();
    void solver(Solucion*);
  private:
    int leftIndex;
    int middleIndex;
    int rigthIndex;
    std::vector<int> numbersVector;
};

#endif /* MERGESORTP_P_ */