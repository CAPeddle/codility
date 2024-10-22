#include "gtest/gtest.h"
// test.cpp
#include <string>
#include <vector>

#include "CleanProject.h"

using namespace std;

TEST(BitMaskOf, BasicCases) {
  auto actual1 = LetterSequenceBasedBitmaskOf("dega", "defbcga");
  auto expected1 = 99;
  EXPECT_EQ(actual1, expected1);

  auto actual2 = LetterSequenceBasedBitmaskOf("def", "defbcga");
  auto expected2 = 112;
  EXPECT_EQ(actual2, expected2);
}

TEST(SortedLetterFrequency, BasicCases) {
  vector<string> S3 = {"bc", "edf", "fde", "dge", "abcd"};
  auto actual1 = getSortedLetterFrequency(S3);
  auto expected1 = "debcfag";
  EXPECT_EQ(actual1, expected1);
}

TEST(GetFullCharSetNumber, BasicCases) {
  std::string fullCharset = "defbcga";
  uint actual1 = LetterSequenceBasedBitmaskOf(fullCharset, fullCharset);
  auto expected1 = 127;
  EXPECT_EQ(actual1, expected1);
}

TEST(MaxNumberOfBits, BasicCases) {
  uint actual1 = HasAtmostBitsSet(100, 4);
  auto expected1 = true;
  EXPECT_EQ(actual1, expected1);

  uint actual2 = HasAtmostBitsSet(102, 4);
  auto expected2 = true;
  EXPECT_EQ(actual2, expected2);

  uint actual3 = HasAtmostBitsSet(55, 4);
  auto expected3 = false;
  EXPECT_EQ(actual3, expected3);

  uint actual4 = HasAtmostBitsSet(110, 4);
  auto expected4 = false;
  EXPECT_EQ(actual4, expected4);

  uint actual5 = HasAtmostBitsSet(0, 4);
  auto expected5 = true;
  EXPECT_EQ(actual5, expected5);

  uint actual6 = HasAtmostBitsSet(31, 4);
  auto expected6 = false;
  EXPECT_EQ(actual6, expected6);

  uint actual7 = HasAtmostBitsSet(103, 4);
  auto expected7 = false;
  EXPECT_EQ(actual7, expected7);
}

TEST(NumBuildable, BasicCases) {
  vector<string> S4 = {"bc", "edf", "fde", "dge", "abcd"};
  auto actual4 = NumBuildable(S4, "def");
  auto expected4 = 2;
  EXPECT_EQ(actual4, expected4);

  vector<string> S3 = {"bc", "edf", "fde", "dge", "abcd"};
  auto actual3 = NumBuildable(S3, "defg");
  auto expected3 = 3;
  EXPECT_EQ(actual3, expected3);

  vector<string> S5 = {"abc", "def", "ghi"};
  auto actual5 = NumBuildable(S5, "abcdefghi");
  auto expected5 = 3;
  EXPECT_EQ(actual5, expected5);

  vector<string> S6 = {"abc", "def", "ghi"};
  auto actual6 = NumBuildable(S6, "abc");
  auto expected6 = 1;
  EXPECT_EQ(actual6, expected6);

  vector<string> S7 = {"abc", "def", "ghi"};
  auto actual7 = NumBuildable(S7, "xyz");
  auto expected7 = 0;
  EXPECT_EQ(actual7, expected7);

  vector<string> S8 = {"a", "b", "c"};
  auto actual8 = NumBuildable(S8, "abc");
  auto expected8 = 3;
  EXPECT_EQ(actual8, expected8);

  vector<string> S9 = {"a", "b", "c"};
  auto actual9 = NumBuildable(S9, "a");
  auto expected9 = 1;
  EXPECT_EQ(actual9, expected9);

  vector<string> S10 = {"abcdefghij", "abcdefghij", "abcdefghij"};
  auto actual10 = NumBuildable(S10, "abcdefghij");
  auto expected10 = 3;
  EXPECT_EQ(actual10, expected10);

  vector<string> S11 = {"abcdefghij", "abcdefghij", "abcdefghij"};
  auto actual11 = NumBuildable(S11, "abcdefghi");
  auto expected11 = 0;
  EXPECT_EQ(actual11, expected11);
}

TEST(SolutionTest, BasicCases) {
  vector<string> S4 = {"bc", "edf", "fde", "dge", "abcd"};
  auto actual4 = solution(S4, 4);
  auto expected4 = 3;
  EXPECT_EQ(actual4, expected4);

  vector<string> S1 = {"abc", "abb", "cb", "a", "bbb"};
  auto actual = solution(S1, 2);
  auto expected = 3;
  EXPECT_EQ(actual, expected);

  vector<string> S2 = {"adf", "jjbh", "jcgj", "eijj", "adf"};
  EXPECT_EQ(solution(S2, 3), 2);

  vector<string> S3 = {"abcd", "efgh"};
  EXPECT_EQ(solution(S3, 3), 0);
}

TEST(SolutionTest, EdgeCases) {
  vector<string> S5 = {};
  EXPECT_EQ(solution(S5, 2), 0);

  vector<string> S6 = {"a", "b", "c"};
  EXPECT_EQ(solution(S6, 0), 0);

  vector<string> S7 = {"a", "b", "c"};
  EXPECT_EQ(solution(S7, 3), 3);

  vector<string> S8 = {"a", "aa", "aaa"};
  EXPECT_EQ(solution(S8, 1), 3);

  vector<string> S9 = {"abcdefghij", "abcdefghij", "abcdefghij"};
  EXPECT_EQ(solution(S9, 10), 3);
}

TEST(SolutionTest, Phind_Tests) {
  std::vector<std::string> S = {"abc", "def", "ghi"};
  int K = 3;
  int expected = 1;
  int actual = solution(S, K);
  EXPECT_EQ(actual, expected);

  std::vector<std::string> S10 = {"abcdefghij", "abcdefghij"};
  int K10 = 10;
  int expected10 = 2;
  int actual10 = solution(S10, K10);
  EXPECT_EQ(actual10, expected10);

  std::vector<std::string> S11 = {"ab", "ac", "bc"};
  int K11 = 2;
  int expected11 = 1;
  int actual11 = solution(S11, K11);
  EXPECT_EQ(actual11, expected11);

  std::vector<std::string> S13 = {"abc", "def", "ghi"};
  int K13 = 1;
  int expected13 = 0;
  int actual13 = solution(S13, K13);
  EXPECT_EQ(actual13, expected13);

  std::vector<std::string> S14 = {"abcdefghij"};
  int K14 = 10;
  int expected14 = 1;
  int actual14 = solution(S14, K14);
  EXPECT_EQ(actual14, expected14);

  std::vector<std::string> S15 = {"ab", "cd", "ef"};
  int K15 = 3;
  int expected15 = 1;
  int actual15 = solution(S15, K15);
  EXPECT_EQ(actual15, expected15);
}

TEST(SolutionTest, AdditionalEdgeCases) {
  // Edge case: Minimum N and K
  vector<string> S1 = {"a"};
  EXPECT_EQ(solution(S1, 1), 1);

  // Edge case: Maximum N and minimum K
  vector<string> S2(50000, "a");
  EXPECT_EQ(solution(S2, 1), 50000);

  // Edge case: Maximum N and maximum K
  vector<string> S3(50000, "abcdefghij");
  EXPECT_EQ(solution(S3, 10), 50000);

  // Edge case: Strings with maximum length
  vector<string> S4 = {"abcdefghij", "abcdefghij", "abcdefghij"};
  auto actual = solution(S4, 9);
  auto expected = 0;
  EXPECT_EQ(actual, expected);

  // Edge case: Strings with overlapping characters
  vector<string> S5 = {"abc", "bcd", "cde", "def", "efg"};
  auto actual1 = solution(S5, 3);
  auto expected1 = 1;
  EXPECT_EQ(actual1, expected1);

  // Edge case: All strings are the same
  vector<string> S6 = {"abc", "abc", "abc"};
  EXPECT_EQ(solution(S6, 3), 3);

  // Edge case: No strings can be built
  vector<string> S7 = {"abc", "def", "ghi"};
  EXPECT_EQ(solution(S7, 0), 0);

  // Edge case: All strings can be built with fewer letters than K
  vector<string> S8 = {"a", "b", "c"};
  EXPECT_EQ(solution(S8, 10), 3);

  // Edge case: Strings with non-overlapping characters
  vector<string> S9 = {"abc", "def", "ghi"};
  EXPECT_EQ(solution(S9, 3), 1);

  // Edge case: Large input with mixed string lengths
  vector<string> S10;
  for (int i = 0; i < 25000; ++i) {
    S10.push_back("abc");
    S10.push_back("defghij");
  }
  EXPECT_EQ(solution(S10, 7), 25000);
}

/*

You are given an array S made of N strings and an integer K.
Choose at most K letters from the alphabet that will allow you to build as
many strings from array S as possible. Any of the chosen letters can be used
multiple times when building the strings. What is the maximum number of
strings from S that can be built? Write a function: int solution
(vector<string> &S, int K); that, given an array S and an integer K, returns
the maximum number of strings from S that can be built. Examples:

Given S = ["abc", "abb", "cb", "a", "bbb"] and K = 2, the function should
return 3. Strings "abb", "a" and "bbb" can be built using the two letters 'a'
and 'b'.

Given S = ["adf", "jjbh", "jcgj", "eijj", "adf"] and K = 3, the function
should return 2. Two strings "adf" can be built using three letters 'a', 'd'
and 'f'.

Given S = ["abcd", "efgh"] and K = 3, the function should return O. It is not
possible to build any string from S using at most three letters.

Given S = ["bc", "edf", "fde", "dge", "abcd"] and K = 4, the function should
return 3. Strings "edf", "fde" and "dge" can be built using the four letters
'd', 'e', 'f' and 'g'.

Write an efficient algorithm for the following assumptions:
• N is an integer within the range [1..50,000];
• K is an integer within the range [1..10];
• each string in S has a length within the range [1..15];
• each string in S is made from only the first ten lowercase letters of the
alphabet ('a'-'j').

*/