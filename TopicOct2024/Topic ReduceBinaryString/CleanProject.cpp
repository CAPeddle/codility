// CleanProject.cpp

#include "CleanProject.h"

#include <bitset>
#include <string>

int solution(std::string &S) {
  int operations = 0;

  S.erase(0, S.find_first_not_of('0'));

  if (S.empty()) {
    return 0;
  }

  while (S != "0") {
    if (S.back() == '0') {
      // Remove the last character (equivalent to dividing by 2)
      S.pop_back();
    } else {
      // Change the last character to '0' (equivalent to subtracting 1)
      S.back() = '0';
    }
    operations++;
  }

  return operations;
}