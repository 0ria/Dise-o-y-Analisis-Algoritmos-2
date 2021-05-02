#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>

class Point
{
private:
  std::vector<float> coordinates;
public:
  Point(/* args */);
  Point(int);
  Point(std::string);
  ~Point();
  void printCoords(void);
  inline std::vector<float> getCoords(void) { return coordinates; };
  float& operator[](int);
};


