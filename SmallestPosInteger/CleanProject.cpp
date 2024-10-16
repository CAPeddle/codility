// CleanProject.cpp
#include "CleanProject.h"

#include <algorithm>

int solution(std::vector<int>& A) {
  // The following std::sort() is crucial to the algorithm!
  std::sort(A.begin(), A.end());
  auto iter = std::lower_bound(A.begin(), A.end(), 1);
  int smallestIntNotFound = 1;

  while (iter != A.end()) {
    if (*iter == smallestIntNotFound) {
      // The list *does* have <smallestIntNotFound>,
      // skip all occurrences and look for next
      // integer value
      while ((++iter != A.end()) && (*iter == smallestIntNotFound));
      ++smallestIntNotFound;
    } else {
      // <smallestIntNotFound> was *not* found
      break;
    }
  }

  return smallestIntNotFound;
}