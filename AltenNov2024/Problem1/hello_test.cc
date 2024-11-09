#include "gtest/gtest.h"

// Demonstrate some basic assertions.
TEST(AltenProb1, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

// test.cpp
#include "CleanProject.h"
// #include "pch.h"

TEST(AltenProb1, DISABLED_TestCleanProject_TestSol_Test1) {
  std::vector<int> A = {3, 8, 9, 7, 6};
  std::vector<int> result = solution(A, 3);
  std::vector<int> expected = {9, 7, 6, 3, 8};
  EXPECT_EQ(result, expected);
}

/*

the problem statement is to cheange one line of code to make the code pass
#include <algorithm>
#include <vector>

int solution(vector<int>& A) {
    int ans = 0;
    for (uint i = 1; i < A.size(); i++) {
        if (ans > A[i]) {
            ans = A[i];
        }
    }
    return ans;
}

change the for loop to check from 0

*/