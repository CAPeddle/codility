#include "gtest/gtest.h"

// https://thezealousprogrammer.wordpress.com/2022/12/29/preparing-for-and-taking-a-codility-technical-coding-interview/

//  // Demonstrate some basic assertions.
//  TEST(HelloTest, BasicAssertions) {
//    // Expect two strings not to be equal.
//    EXPECT_STRNE("hello", "world");
//    // Expect equality.
//    EXPECT_EQ(7 * 6, 42);
//  }

// test.cpp
#include "CleanProject.h"
// #include "pch.h"

TEST(TestDemo, Example_1) {
  std::vector<int> A = {1, 2, 3};
  EXPECT_EQ(solution(A), 4);
}

TEST(TestDemo, Example_2) {
  std::vector<int> A = {-1, -3};
  EXPECT_EQ(solution(A), 1);
}

TEST(TestDemo, Mine_1) {
  std::vector<int> A = {1, 3, 6, 4, 1, 2};
  EXPECT_EQ(solution(A), 5);
}

TEST(TestDemo, Mine_2) {
  std::vector<int> A = {-1000000};
  EXPECT_EQ(solution(A), 1);
}

TEST(TestDemo, Mine_3) {
  std::vector<int> A = {1};
  EXPECT_EQ(solution(A), 2);
}

TEST(TestDemo, Mine_4) {
  std::vector<int> A = {2};
  EXPECT_EQ(solution(A), 1);
}

TEST(TestDemo, Mine_5) {
  std::vector<int> A = {1000000};
  EXPECT_EQ(solution(A), 1);
}

TEST(TestDemo, Mine_6) {
  std::vector<int> A = {-1000000, -1000000};
  EXPECT_EQ(solution(A), 1);
}

TEST(TestDemo, Mine_7) {
  std::vector<int> A = {-1000000, 1000000};
  EXPECT_EQ(solution(A), 1);
}

TEST(TestDemo, Mine_8) {
  std::vector<int> A = {0, 0, 0, 0, 0};
  EXPECT_EQ(solution(A), 1);
}

TEST(TestDemo, Mine_9) {
  std::vector<int> A = {1, 1, 1, 1, 1};
  EXPECT_EQ(solution(A), 2);
}

TEST(TestDemo, Mine_10) {
  std::vector<int> A = {2, 2, 2, 2, 2};
  EXPECT_EQ(solution(A), 1);
}

TEST(TestDemo, Mine_11) {
  std::vector<int> A = {2, 2, 2, 2, 1};
  EXPECT_EQ(solution(A), 3);
}

TEST(TestDemo, Mine_12) {
  std::vector<int> A;

  for (int i = 0; i < 100000; ++i) {
    A.push_back(-9);
  }

  EXPECT_EQ(solution(A), 1);
}

TEST(TestDemo, Mine_13) {
  std::vector<int> A = {-1000000};

  for (int i = -49999; i < 50001; ++i) {
    A.push_back(i);
  }

  EXPECT_EQ(solution(A), 50001);
}
