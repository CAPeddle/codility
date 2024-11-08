// https://molchevskyi.medium.com/best-solutions-for-codility-lessons-lesson-2-arrays-5c3e3ee2299c

#include <algorithm>
#include <numeric>

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

TEST(TestCleanProject, Example1) {
  std::vector<int> A = {9, 3, 9, 3, 9, 7, 9};
  int result = solution(A);
  int expected = 7;
  EXPECT_EQ(result, expected);
}

TEST(TestCleanProject, NumberOfElementsIs1) {
  std::vector<int> A = {9};
  int result = solution(A);
  int expected = 9;
  EXPECT_EQ(result, expected);
}

/// <summary>
/// This test could put 1 million even numbers in the vector and then one known uneven.
/// but that is a TODO, hence disabled
/// </summary>
/// <param name=""></param>
/// <param name=""></param>
TEST(TestCleanProject, DISABLED_NumberOfElementsIs1Million) {
  std::vector<int> V;

  for (int i = 0; i < 1000000 - 1; ++i) {
    V.push_back(i);
  }

  int result = solution(V);
  int expected = 3;
  EXPECT_EQ(result, expected);
}