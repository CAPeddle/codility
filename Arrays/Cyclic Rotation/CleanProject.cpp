// CleanProject.cpp
#include "CleanProject.h"

#include <algorithm>
#include <vector>

template <class T>
void reverse(std::vector<T> &v) {
  size_t begin = 0;
  size_t end = v.size() - 1;
  while (begin < end) {
    std::swap(v[begin], v[end]);
    begin++;
    end--;
  }
}

template <class T>
void shiftRight(std::vector<T> &v, int K) {
  int n = v.size();
  if (n == 0) return;
  K = K % n;  // In case K is greater than the size of the vector
  std::reverse(v.begin(), v.end());
  std::reverse(v.begin(), v.begin() + K);
  std::reverse(v.begin() + K, v.end());
}

std::vector<int> solution(std::vector<int> &A, int K) {
  std::vector<int> result;

  shiftRight(A, K);

  return A;
}