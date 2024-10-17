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

TEST(TestCleanProject, Example1) {
  std::vector<int> A = {2, 3, 1, 5};
  int result = solution(A);
  int expected = 4;
  EXPECT_EQ(result, expected);
}

TEST(TestCleanProject, Example2) {
  std::vector<int> A = {3, 1};
  int result = solution(A);
  int expected = 2;
  EXPECT_EQ(result, expected);
}

TEST(TestCleanProject, TestforOverflow_LongLongSolution) {
  constexpr int N = 100000;
  std::vector<int> A(N);
  std::iota(A.begin(), A.end(), 1);

  A[N - 1] = N + 1;

  // std::cout << "A Size: " << A.size() << std::endl;
  // for (int i = A.size() - 5; i < A.size(); ++i) {
  //   std::cout << A[i] << " ";
  // }
  // std::cout << std::endl;

  int result = solution_long_long(A);
  int expected = N;
  EXPECT_EQ(result, expected);
}

TEST(TestCleanProject, TestforOverflow_IntSolution) {
  constexpr int N = 100000;
  std::vector<int> A(N);
  std::iota(A.begin(), A.end(), 1);

  A[N - 1] = N + 1;

  // std::cout << "A Size: " << A.size() << std::endl;
  // for (int i = A.size() - 5; i < A.size(); ++i) {
  //   std::cout << A[i] << " ";
  // }
  // std::cout << std::endl;

  int result = solution(A);
  int expected = N;
  EXPECT_EQ(result, expected);
}