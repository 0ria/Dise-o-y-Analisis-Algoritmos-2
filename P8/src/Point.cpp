#include "../include/Point.h"

Point::Point(/* args */) {
  coordinates.resize(0);
}

Point::Point(std::string pt) {
  std::replace(pt.begin(), pt.end(), ',', '.');
  std::istringstream iss(pt);
  while (iss >> pt) {
    coordinates.push_back(std::stof(pt));
  }
}

Point::Point(int sz) { 
  coordinates.resize(sz); 
  std::fill(coordinates.begin(), coordinates.end(), 0);
  }

void Point::printCoords() {
  std::cout << "[ ";
  for (auto it : coordinates) {
    std::cout << it << " ";
  }
  std::cout << "] ";
}

Point::~Point() {}

float& Point::operator[](int index) {
  if (index >= coordinates.size()) {
    std::cout << "Error index out of range\n";
    exit(0);
  }
  return coordinates[index];
}