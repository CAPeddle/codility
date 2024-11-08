#include "CleanProject.h"
#include "gtest/gtest.h"

// Test case for the solution method
TEST(SolutionTest, BasicAssertions) {
  // Test case 1
  std::string input1 = "world";
  int expected1 = 1;
  EXPECT_EQ(solution(input1), expected1);

  // Test case 2
  std::string input2 = "dddd";
  int expected2 = 4;
  EXPECT_EQ(solution(input2), expected2);

  // Test case 3
  std::string input3 = "cycle";
  int expected3 = 2;
  EXPECT_EQ(solution(input3), expected3);

  // Test case 4
  std::string input4 = "abba";
  int expected4 = 2;
  EXPECT_EQ(solution(input4), expected4);

  // Additional test cases can be added here
}

TEST(SolutionTest, DISABLED_MaxString) {
  std::string A;
  while (A.size() < 1000000) {
    for (char c = 'a'; c <= 'z' && A.size() < 1000000; ++c) {
      A += c;
    }
  }

  // std::cout << A << std::endl;

  int result = solution(A);
  auto expected = 5;
  EXPECT_EQ(result, expected);
}

TEST(SolutionTest, Example2) {
  std::string A;

  for (int i = 0; i < 10; ++i) {
    for (char c = 'a'; c <= 'z' && A.size() < 1000000; ++c) {
      A += c;
    }
  }

  // std::cout << A << std::endl;

  int result = solution(A);
  auto expected = 10;
  EXPECT_EQ(result, expected);
}