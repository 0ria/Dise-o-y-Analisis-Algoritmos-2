#include "../include/LocalSearch.h"

LocalSearch::LocalSearch(/* args */) {}

LocalSearch::LocalSearch(std::vector<Point>& v) : pointVector(v) {}

LocalSearch::~LocalSearch() {}

float LocalSearch::getDist(Point& pt1, Point& pt2) {
  Point aux(pt1.getCoords().size());
  for (int i = 0; i < aux.getCoords().size(); i++) {
    aux[i] = pow(pt2[i] - pt1[i], 2);
  }
  float sum = 0.0;
  for (auto& it : aux.getCoords()) sum += it;
  return sqrt(sum);
}

float LocalSearch::getZDist(std::vector<Point>& sol) {
  float aux = 0.0;
  for (int i = 0; i < sol.size(); i++)
    for (int j = i + 1; j < sol.size(); j++) aux += getDist(sol[i], sol[j]);
  return aux;
}

bool LocalSearch::isNotContained(std::vector<Point> v, Point pt) {
  for (int i = 0; i < v.size(); i++) {
    if (pt.getCoords() == v[i].getCoords())
      return false;
  }
  return true;
}

std::vector<Point> LocalSearch::getBetterSol(void) {
  auto sol = actualSol;
  auto bestSol = actualSol;
  float actualZDist = getZDist(sol);
  float newZDist;
  for (int i = 0; i < actualSol.size(); i++) {
    for (int j = 0; j < pointVector.size(); j++) {
      if (isNotContained(sol, pointVector[j])) {
        sol[i] = pointVector[j];
        newZDist = getZDist(sol);
        if (actualZDist < newZDist) {
          actualZDist = newZDist;
          bestSol = sol;
        }
        sol = actualSol;
      }
    }
  }
  return bestSol;
}