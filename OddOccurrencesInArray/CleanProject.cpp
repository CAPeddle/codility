// CleanProject.cpp
#include "CleanProject.h"

#include <algorithm>

int solution(std::vector<int>& A) {
  int res = 0;
  for (auto i : A) {
    res ^= i;
  }
  return res;
}