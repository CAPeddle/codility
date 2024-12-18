#include "gtest/gtest.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

// test.cpp
#include "CleanProject.h"
// #include "pch.h"

TEST(TestCleanProject, DISABLED_TestCleanProject_TestSol_Test1) {
  std::vector<int> A = {3, 8, 9, 7, 6};
  std::vector<int> result = solution(A, 3);
  std::vector<int> expected = {9, 7, 6, 3, 8};
  EXPECT_EQ(result, expected);
}