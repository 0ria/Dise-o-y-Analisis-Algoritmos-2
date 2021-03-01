#pragma once
#include <vector>
#include <iostream>
class Matrix {
 private:
  std::vector<std::vector<int> > matrix;

 public:
  Matrix(std::vector<std::vector<int> >);
  virtual Matrix* product(Matrix*) = 0;
  std::vector<std::vector<int> > getMatrix(void);
  void showMatrix(void);
  void transpose(void);
};