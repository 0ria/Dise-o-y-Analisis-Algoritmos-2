#include "../include/Lcs.h"

Lcs::Lcs(/* args */) {}

Lcs::Lcs(std::string& firstSeq, std::string& secondSeq)
    : firstSequence(firstSeq), secondSequence(secondSeq) {
  reset();
}

void Lcs::reset() {
  std::pair<int, std::string> aux = {0, ""};
  finalTable.resize(firstSequence.size() + 1);
  for (int i = 0; i < finalTable.size(); i++) {
    finalTable[i].resize(secondSequence.size() + 1);
    std::fill(finalTable[i].begin(), finalTable[i].end(), aux);
  }
}

Lcs::~Lcs() {}

void Lcs::solve() {
  maxSubstrSize = 0;
  for (int i = 0; i < firstSequence.size(); i++) {
    if (firstSequence.size() - i + 1 < maxSubstrSize) {
      break;
    }
    generateSolution(i);
  }
}

void Lcs::calculateLcs(int startValue) {
  for (int i = startValue; i <= firstSequence.size(); i++) {
    for (int j = 0; j <= secondSequence.size(); j++) {
      if (i == 0 || j == 0)
        finalTable[i][j].first = 0;
      else if (firstSequence[i - 1] == secondSequence[j - 1]) {
        finalTable[i][j].first = finalTable[i - 1][j - 1].first + 1;
        finalTable[i][j].second =
            finalTable[i - 1][j - 1].second + firstSequence[i - 1];
      } else {
        finalTable[i][j] =
            (finalTable[i - 1][j].first >= finalTable[i][j - 1].first)
                ? finalTable[i - 1][j]
                : finalTable[i][j - 1];
      }
    }
  }
}

void Lcs::generateSolution(int startValue) {
  calculateLcs(startValue);
  if (finalTable[firstSequence.size()][secondSequence.size()].first >
      maxSubstrSize) {
    maxSubstrSize =
        finalTable[firstSequence.size()][secondSequence.size()].first;
  }
  if (finalTable[firstSequence.size()][secondSequence.size()].first ==
      maxSubstrSize) {
    solutions.insert(finalTable[firstSequence.size()][secondSequence.size()]);
  }
  reset();
}

void Lcs::getResults(void) {
  for (auto it : solutions) {
    std::cout << "Size of max lcs: " << it.first << "\n";
    std::cout << "String: " << it.second << "\n\n";
  }
}