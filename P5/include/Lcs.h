#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>

class Lcs {
 private:
  std::string firstSequence;
  std::string secondSequence;
  std::vector<std::vector<std::pair<int, std::string> > > finalTable;
  std::set<std::pair<int, std::string> > solutions;
  int maxSubstrSize;

 public:
  Lcs(/* args */);
  Lcs(std::string&, std::string&);
  void calculateLcs(int);
  void getResults(void);
  void solve();
  void generateSolution(int);
  void reset(void);
  ~Lcs();
};