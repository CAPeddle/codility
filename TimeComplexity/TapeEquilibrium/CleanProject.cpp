// CleanProject.cpp

#include "CleanProject.h"

#include <algorithm>
#include <limits>
#include <numeric>
#include <vector>

int solution(std::vector<int> &A) {
  if (A.size() == 2) return abs(A.front() - A.back());

  long long sum = std::accumulate(A.begin(), A.end(), 0);

  long long left = 0;
  long long right = sum;
  int minDifference = std::numeric_limits<int>::max();

  for (size_t i = 0; i < A.size() - 1; ++i) {
    left += A[i];
    right -= A[i];
    minDifference =
        std::min(minDifference, static_cast<int>(std::abs(left - right)));
  }

  return minDifference;
}