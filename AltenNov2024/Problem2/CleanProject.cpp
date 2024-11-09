// CleanProject.cpp

#include "CleanProject.h"

#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

int solution(std::string &S) {
  std::unordered_set<char> charSet;
  int substrCount = 0;

  if (S.empty()) {
    return 0;
  }

  for (char c : S) {
    if (charSet.find(c) != charSet.end()) {
      substrCount++;
      charSet.clear();
    }
    charSet.insert(c);
  }

  if (!charSet.empty()) {
    substrCount++;
  }

  return substrCount;
}