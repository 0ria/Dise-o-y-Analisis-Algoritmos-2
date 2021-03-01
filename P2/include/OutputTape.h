#include "BasicTape.h"

class OutputTape : public BasicTape
{
private:
  //std::vector<int> tape;
  //int pos;
public:
  OutputTape(/* args */);
  OutputTape(std::ofstream&);
  ~OutputTape();
};
