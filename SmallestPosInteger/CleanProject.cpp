// CleanProject.cpp
#include "CleanProject.h"

#include <algorithm>

int solution(std::vector<int>& A) {
  std::sort(A.begin(), A.end());
  int smallestIntNotFound = 1;

  for (int num : A) {
    if (num == smallestIntNotFound) {
      ++smallestIntNotFound;
    } else if (num > smallestIntNotFound) {
      break;
    }
  }

  return smallestIntNotFound;
}
