#ifndef MERGESORTS_P_
#define MERGESORTS_P_

#include "../framework/Solucion.h"
#include <vector>
#include <utility>

class MergesortS : public Solucion {
  public:
    MergesortS();
    virtual ~MergesortS();

    void resolver();
    void mezcla(std::pair<Solucion*, Solucion*>);
    Solucion* getInstance();

    void setValor(std::vector<int>, int, int, int);
    void merge(std::vector<int>, std::vector<int>);

  private:
    int rightIndex;
    int middleIndex;
    int leftIndex;
    std::vector<int> numbersVector;
};

#endif /* MERGESORTS_P_ */