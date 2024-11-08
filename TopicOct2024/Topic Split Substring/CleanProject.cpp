// CleanProject.cpp

#include "CleanProject.h"

#include <algorithm>
#include <unordered_set>
#include <vector>

int solution(std::string &S) {
  std::unordered_set<char> charSet;
  int substrCount = 0;

  for (char c : S) {
    auto result = charSet.insert(c);
    if (!result.second) {
      substrCount++;
      charSet.clear();
      charSet.insert(c);
    }
  }

  if (!charSet.empty()) {
    substrCount++;
  }

  return substrCount;
}