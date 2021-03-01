#pragma once
#include "matrixClass.h"

class RowMatrix : public Matrix {
  public:
    RowMatrix(std::vector<std::vector<int> >);
    Matrix* product(Matrix*);
};