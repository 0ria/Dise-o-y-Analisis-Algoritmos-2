#ifndef QUICKSORTS_P_
#define QUICKSORTS_P_

#include "../framework/Solucion.h"
#include <vector>
#include <utility>

class QuicksortS : public Solucion {
 private:
  std::vector<int> numbersVector;
 public:
  QuicksortS(/* args */);
  ~QuicksortS();

  void resolver();
  void mezcla(std::pair<Solucion*, Solucion*>);
  Solucion* getInstance();

  void setValor(std::vector<int>);
};

#endif /* QUICKSORTS_P_ */