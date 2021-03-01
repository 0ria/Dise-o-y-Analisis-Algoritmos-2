#pragma once
#include "matrixClass.h"

class ColumnMatrix : public Matrix {
  public:
    ColumnMatrix(std::vector<std::vector<int> >);
    Matrix* product(Matrix*);
};