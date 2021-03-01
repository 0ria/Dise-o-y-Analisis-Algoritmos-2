#include "../include/matrixClass.h"

Matrix::Matrix(std::vector<std::vector<int> > m) : matrix(m) {}

std::vector<std::vector<int> > Matrix::getMatrix(void) { return matrix; }

void Matrix::showMatrix(void) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}

void Matrix::transpose(void) {
  std::vector<std::vector<int> > transposedMatrix;
  std::vector<int> auxVec;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[i].size(); j++) {
      auxVec.push_back(matrix[j][i]);
    }
  transposedMatrix.push_back(auxVec);
  auxVec.clear();
  }
  matrix = transposedMatrix;
}