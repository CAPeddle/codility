// CleanProject.cpp

#include "CleanProject.h"

#include <algorithm>
#include <numeric>
#include <vector>

int solution(
    std::vector<int>& v) {  // Here +1 needs to find size of full sequence with
  // the missing element
  int v_size = v.size() + 1;
  // Find sum of all elements of the sequence
  int sumOfAllElements = (v_size * (1 + v_size)) / 2;
  int missing_element =
      sumOfAllElements - std::accumulate(v.begin(), v.end(), 0);
  return missing_element;
}

int solution_long_long(std::vector<int>& V) {
  int result;

  int n = V.size() + 1;
  long long total = static_cast<long long>(n) * (n + 1) / 2;
  long long sum_of_V = std::accumulate(V.begin(), V.end(), 0LL);
  result = static_cast<int>(total - sum_of_V);

  return result;
}

/*

https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/

An array A consisting of N different integers is given. The array contains
integers in the range [1..(N + 1)], which means that exactly one element is
missing.

Your goal is to find that missing element.

Write a function:

    int solution(vector<int> &A);

that, given an array A, returns the value of the missing element.

For example, given array A such that:
  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5

the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [0..100,000];
        the elements of A are all distinct;
        each element of array A is an integer within the range [1..(N + 1)].

Copyright 2009–2024 by Codility Limited. All Rights Reserved. Unauthorized
copying, publication or disclosure prohibited.

*/