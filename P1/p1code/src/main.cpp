#include <cstdlib>
#include <iostream>
#include <chrono>

#include "../include/columnMatrix.h"
#include "../include/rowMatrix.h"

const int MATRIXSIZE = 3000;
const int MAXPOSIBLENUMBER = 100;

std::vector<std::vector<int> > fillMatrix() {
  std::vector<std::vector<int> > m;
  std::vector<int> row;
  for (int j = 0; j < MATRIXSIZE; j++) {
    for (int i = 0; i < MATRIXSIZE; i++) {
      row.push_back(rand() % MAXPOSIBLENUMBER + 1);
    }
    m.push_back(row);
    row.clear();
  }
  return m;
}

int main(void) {
  typedef std::chrono::milliseconds s;
  std::vector<std::vector<int> > initialMatrix1 = fillMatrix();
  std::vector<std::vector<int> > initialMatrix2 = fillMatrix();
  Matrix* rowm1 = new RowMatrix(initialMatrix1);
  Matrix* rowm2 = new RowMatrix(initialMatrix2);
  Matrix* colm1 = new ColumnMatrix(initialMatrix1);
  Matrix* colm2 = new ColumnMatrix(initialMatrix2);
  colm1 -> transpose();
  colm2 -> transpose();

/*
  rowm1->showMatrix();
  std::cout << "\n";
  rowm2->showMatrix();
  std::cout << "\n";

  colm1->showMatrix();
  std::cout << "\n";
  colm2->showMatrix();
  std::cout << "\n";
*/
  auto before = std::chrono::high_resolution_clock::now();
  Matrix* multiMatrx = rowm1 -> product(rowm2);
  auto after = std::chrono::high_resolution_clock::now();
  auto time = std::chrono::duration_cast<s>(after - before).count();
  std::cout << "The time for row multiplication was: " << time << "\n";
  //multiMatrx -> showMatrix();
  std::cout << "\n";
  
  before = std::chrono::high_resolution_clock::now();
  Matrix* multiMatrxCol = colm1 -> product(colm2);
  after = std::chrono::high_resolution_clock::now();
  time = std::chrono::duration_cast<s>(after - before).count();
  std::cout << "The time for column multiplication was: " << time << "\n";
  //multiMatrxCol -> showMatrix();
}