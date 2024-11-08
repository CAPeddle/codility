// CleanProject.cpp

#include "CleanProject.h"

#include <algorithm>
#include <vector>

int solution(std::vector<int> &A) {
  int N = A.size();
  std::vector<long long> lower(N);
  std::vector<long long> upper(N);

  for (int i = 0; i < N; ++i) {
    lower[i] = i - (long long)A[i];
    upper[i] = i + (long long)A[i];
  }

  std::sort(lower.begin(), lower.end());
  std::sort(upper.begin(), upper.end());

  int intersections = 0;
  int j = 0;

  for (int i = 0; i < N; ++i) {
    while (j < N && upper[i] >= lower[j]) {
      intersections += j;
      intersections -= i;
      ++j;
    }
    if (intersections > 10000000) return -1;
  }

  return intersections;
}