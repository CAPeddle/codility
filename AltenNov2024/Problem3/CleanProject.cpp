// CleanProject.cpp

#include "CleanProject.h"

#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> &A, vector<int> &B) {
  int N = A.size();
  if (N < 2) return 0;

  std::vector<long long> prefixSumA(N + 1, 0);
  std::vector<long long> prefixSumB(N + 1, 0);

  // Compute prefix sums for A and B
  for (int i = 0; i < N; ++i) {
    prefixSumA[i + 1] = prefixSumA[i] + A[i];
    prefixSumB[i + 1] = prefixSumB[i] + B[i];
  }

  int fairIndexes = 0;

  // Check for each index K
  for (int K = 1; K < N; ++K) {
    long long sumA1 = prefixSumA[K];
    long long sumA2 = prefixSumA[N] - prefixSumA[K];
    long long sumB1 = prefixSumB[K];
    long long sumB2 = prefixSumB[N] - prefixSumB[K];

    if (sumA1 == sumA2 && sumA1 == sumB1 && sumA1 == sumB2) {
      fairIndexes++;
    }
  }

  return fairIndexes;
}