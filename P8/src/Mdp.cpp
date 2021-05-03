#include "../include/Mdp.h"

Mdp::Mdp(/* args */) {}

Mdp::Mdp(int totalPoints, int dim, std::vector<Point>& coor)
    : numberOfElements(totalPoints),
      dimensions(dim),
      pointVector(coor),
      ls(pointVector) {}

Mdp::~Mdp() {}

Point Mdp::getCenter(std::vector<Point>& v) {
  Point center(dimensions);

  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < v[i].getCoords().size(); j++) {
      center[j] += v[i][j];
    }
  }

  float div = 1.00 / v.size();
  for (int i = 0; i < dimensions; i++) {
    center[i] *= div;
  }
  return center;
}

float Mdp::getDist(Point& pt1, Point& pt2) {
  Point aux(pt1.getCoords().size());
  for (int i = 0; i < aux.getCoords().size(); i++) {
    aux[i] = pow(pt2[i] - pt1[i], 2);
  }
  float sum = 0.0;
  for (auto& it : aux.getCoords()) sum += it;
  return sqrt(sum);
}

std::vector<int> Mdp::getBetterPoint(int number, std::vector<Point> elem,
                                     Point actualCenter) {
  std::vector<int> selectedElems;
  float actualDist;
  int selectedElementIndex;
  while (selectedElems.size() != number) {
    float maxDist = getDist(elem[0], actualCenter);
    for (int i = 0; i < elem.size(); i++) {
      actualDist = getDist(elem[i], actualCenter);
      if (actualDist >= maxDist) {
        maxDist = actualDist;
        selectedElementIndex = i;
      }
    }
    selectedElems.push_back(selectedElementIndex);
  }
  return selectedElems;
}

float Mdp::getZDist(std::vector<Point>& sol) {
  float aux = 0.0;
  for (int i = 0; i < sol.size(); i++)
    for (int j = i + 1; j < sol.size(); j++) aux += getDist(sol[i], sol[j]);
  return aux;
}

void Mdp::greedy(int m) {
  auto elements = pointVector;
  std::vector<Point> solutions;
  Point center = getCenter(elements);

  while (solutions.size() != m) {
    int index = getBetterPoint(1, elements, center)[0];
    solutions.push_back(elements[index]);
    elements.erase(elements.begin() + index);
    center = getCenter(solutions);
  }
  zDist = getZDist(solutions);
  finalSolutions = solutions;
}

void Mdp::printSol() {
  for (auto it : finalSolutions) it.printCoords();
  std::cout << "\nz: " << zDist;
}

void Mdp::improveSolution(void) {
  ls.setNewSol(finalSolutions);
  auto newSol = ls.getBetterSol();
  if (zDist < getZDist(newSol)) {
    zDist = getZDist(newSol);
    finalSolutions = newSol;
  }
}

/* Para GRASP
  while (solutions.size() != m) {
    std::vector<int> indexes = getBetterPoint(1, elements, center);
    for (auto it: indexes) {
      solutions.push_back(elements[it]);
      elements.erase(elements.begin() + it);
    }
    center = getCenter(solutions);
  }
*/