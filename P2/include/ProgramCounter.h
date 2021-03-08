#include <iostream>

class ProgramCounter {
 private:
  int nextDir;
 public:
  ProgramCounter(/* args */);
  ~ProgramCounter();
  inline void setDir(int newDir) { nextDir = newDir; };
  inline int getDir(void) { return nextDir; };
  void operator=(int);
  void operator++(int);
  std::ostream& operator<<(std::ostream& os);
};
