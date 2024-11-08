#include "gtest/gtest.h"

// Demonstrate some basic assertions.
TEST(NumberOfDiscIntersections, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

// test.cpp
#include "CleanProject.h"

TEST(NumberOfDiscIntersections, TestCleanProject_TestSol_Test1) {
  std::vector<int> A = {3, 8, 9, 7, 6};
  int actual = solution(A);
  int expected = 9;
  EXPECT_EQ(actual, expected);
}