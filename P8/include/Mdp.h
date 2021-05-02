#include "Point.h"
class Mdp {
 private:
  int numberOfElements;
  int dimensions;
  std::vector<Point> pointVector;
  std::vector<Point> finalSolutions;
  float zDist = 0;

 public:
  Mdp(/* args */);
  Mdp(int, int, std::vector<Point>&);
  ~Mdp();
  Point getCenter(std::vector<Point>&);
  float getDist(Point&, Point&);
  std::vector<int> getBetterPoint(int, std::vector<Point>, Point);
  float getZDist(std::vector<Point>&);
  void printSol(void);
  void greedy(int);

};

/*
1: Elem = S;
2: S = ∅;
3: Obtener sc = centro(Elem);
4: repeat
5:    Obtener el elemento s∗ ∈ Elem más alejado de sc;
6:    S = S ∪ {s∗};
7:    Elem = Elem − {s∗};
8:    Obtener sc = centro(S);
9: until (|S| = m)
10: Devolver S;
*/