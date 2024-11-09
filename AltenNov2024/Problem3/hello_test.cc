#include "gtest/gtest.h"
// test.cpp
#include "CleanProject.h"

TEST(AltenProb3, TestCleanProject_TestSol_Test1) {
  std::vector<int> A = {0, 4, -1, 0, 3};
  std::vector<int> B = {0, -2, 5, 0, 3};
  auto result = solution(A, B);
  auto expected = 3;
  EXPECT_EQ(result, expected);

  A = {0, 4, -1, 0, 3};
  B = {0, -2, 5, 0, 3};
  result = solution(A, B);
  expected = 3;
  EXPECT_EQ(result, expected);

  A = {2, -2, -3, 3};
  B = {0, 0, 4, -4};
  result = solution(A, B);
  expected = 3;
  EXPECT_EQ(result, expected);

  A = {4, -1, 0, 3};
  B = {2, 6, 0, 4};
  result = solution(A, B);
  expected = 0;
  EXPECT_EQ(result, expected);

  A = {3, 2, 6};
  B = {4, 1, 6};
  result = solution(A, B);
  expected = 0;
  EXPECT_EQ(result, expected);

  A = {1, 4, 2, -2, 5};
  B = {7, -2, -2, 2, 5};
  result = solution(A, B);
  expected = 2;
  EXPECT_EQ(result, expected);
}

/*
You are given two arrays A and B consisting of N integers each. Index K is named
fair if the four sums (A[0] + ... + A[K-1]), (A[K] + ... + A[N-1]), (B[0] + ...
+ B[K-1]) and (B[K] + ... + B[N-1]) are all equal. In other words, K is the
index where the two arrays, A and B, can be split (into two non-empty arrays
each) in such a way that the sums of the resulting arrays' elements are equal.

For example, given arrays A = [0, 4, -1, 0, 3] and B = [0, -2, 5, 0, 3], index K
= 3 is fair.

The sums of the four subarrays are all equal: 0 + 4 + (-1) = 3; 0 + 3 = 3;
0 + (-2) + 5 = 3 and 0 + 3 = 3. On the other hand, index K = 2 is not fair, the
sums of the subarrays are: 0 + 4 = 4; (-1) + 0 + 3 = 2; 0 + (-2) = -2 and 5 + 0
+ 3 = 8. Write a function: int solution(vector<int> &A, vector<int> &B); which,
given two arrays of integers A and B, returns the total number of fair indexes.
Examples:

Given A = [0, 4, -1, 0, 3] and B = [0, -2, 5, 0, 3], your function should
return 2. The fair indexes are 3 and 4. In both cases, the sums of elements of
the subarrays are equal to 3.
Given A = [2, -2, -3, 3] and B = [0, 0, 4, -4],
your function should return 1. The only fair index is 2. Index 4 is not fair as
the subarrays containing indexes from K to N - 1 would be empty.
Given A = [4,
-1, 0, 3] and B = [-2, 6, 0, 4], your function should return 0. There are no
fair indexes. Given A = [3, 2, 6] and B = [4, 1, 6], your function should return
0.
Given A = [1, 4, 2, -2, 5] and B = [7, -2, -2, 2, 5], your function should
return 2. The fair indexes are 2 and 4.

Write an efficient algorithm for the following assumptions:
• N is an integer within the range [2..100,000];
• each element of arrays A and B is an integer within the range
[-1,000,000,000..1,000,000,000].
*/