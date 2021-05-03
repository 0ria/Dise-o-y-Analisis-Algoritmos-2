#include "Point.h"
class LocalSearch
{
private:
  std::vector<Point> pointVector;
  std::vector<Point> actualSol;
  bool isNotContained(std::vector<Point>, Point);
public:
  LocalSearch(/* args */);
  LocalSearch(std::vector<Point>&);
  ~LocalSearch();
  std::vector<Point> getBetterSol();
  float getZDist(std::vector<Point>&);
  float getDist(Point&, Point&);
  inline void setNewSol(std::vector<Point>& sol) { actualSol = sol; };
};