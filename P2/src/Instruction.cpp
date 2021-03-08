#include "../include/Instruction.h"

Instruction::Instruction(/* args */) {}

/*
Instruction::Instruction(std::string& instrLine) {
  int tagPos = instrLine.find(':');
  if (tagPos == std::string::npos) {
    // There is no tag
    int instrTagPos = instrLine.find(' '); // maybe find_last_of??
    if (instrTagPos == std::string::npos) {
      instruction = instrLine;
      //instruction.erase(std::remove_if(instruction.begin(), instruction.end(), isspace), instruction.end());
    }
    else {
      // There is a space between instruction and operation
      instruction = instrLine.substr(0, instrTagPos);
      operation = instrLine.substr(instrTagPos + 1);
      //instruction.erase(std::remove_if(instruction.begin(), instruction.end(), isspace), instruction.end());
      //operation.erase(std::remove_if(instruction.begin(), instruction.end(), isspace), instruction.end());
    }
  }
  else {
    // There is tag
    tag = instrLine.substr(0, tagPos);
    instrLine = instrLine.substr(tagPos + 1);
    //sigue
    int instrTagPos = instrLine.find(' ');
    if (instrTagPos == std::string::npos) {
      instruction = instrLine;
    }
    else {
      instruction = instrLine.substr(0, instrTagPos);
      operation = instrLine.substr(instrTagPos + 1);
    }
  }
  instruction.erase(std::remove_if(instruction.begin(), instruction.end(), isspace), instruction.end());
  operation.erase(std::remove_if(instruction.begin(), instruction.end(), isspace), instruction.end());
  tag.erase(std::remove_if(instruction.begin(), instruction.end(), isspace), instruction.end());
}
*/