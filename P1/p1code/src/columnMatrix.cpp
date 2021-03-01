#include "../include/columnMatrix.h"

ColumnMatrix::ColumnMatrix(std::vector<std::vector<int> > m) : Matrix(m) {};

Matrix* ColumnMatrix::product(Matrix* m2) {
  std::vector<std::vector<int> > matrixData;
  std::vector<int> auxVect;
  std::vector<std::vector<int> > matrix1 = getMatrix();
  std::vector<std::vector<int> > matrix2 = m2->getMatrix();
  for (int i = 0; i < matrix1.size(); i++){
    for (int j = 0; j < matrix2[i].size(); j++) {
      int resultAux = 0;
      for (int z = 0; z < matrix2.size(); z++) {
        resultAux += matrix1[z][i] * matrix2[j][z];
      }
      auxVect.push_back(resultAux);
      resultAux = 0;
    }
    matrixData.push_back(auxVect);
    auxVect.clear();
  }
  Matrix* matrixFinal = new ColumnMatrix(matrixData);
  return matrixFinal;
}