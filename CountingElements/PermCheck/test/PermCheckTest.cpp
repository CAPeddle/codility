#include <gtest/gtest.h>
#include <vector>

// Import the solution function from the parent directory
// Note: In a real project, you might need to include a header file instead
extern int solution(std::vector<int>& A);

class PermCheckTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Setup code if needed before each test
    }

    void TearDown() override {
        // Cleanup code if needed after each test
    }
};

// Test case for a valid permutation
TEST_F(PermCheckTest, ValidPermutation) {
    std::vector<int> A = {4, 1, 3, 2};
    EXPECT_EQ(solution(A), 1) << "Array {4,1,3,2} should be recognized as a permutation";
}

// Test case for an invalid permutation (missing element)
TEST_F(PermCheckTest, MissingElement) {
    std::vector<int> A = {4, 1, 3};
    EXPECT_EQ(solution(A), 0) << "Array {4,1,3} should not be recognized as a permutation";
}

// Test case for an invalid permutation (duplicate element)
TEST_F(PermCheckTest, DuplicateElement) {
    std::vector<int> A = {4, 1, 3, 3};
    EXPECT_EQ(solution(A), 0) << "Array {4,1,3,3} with duplicate should not be recognized as a permutation";
}

// Test case for a permutation with a different starting number
// Disabled because the problem statement specifies that the permutation should start from 1
// Uncomment if you want to test this case
// TEST_F(PermCheckTest, DifferentStartingNumber) {
//     std::vector<int> A = {5, 6, 7, 8};
//     EXPECT_EQ(solution(A), 1) << "Array {5,6,7,8} should be recognized as a permutation";
// }

// Test case for an empty array
TEST_F(PermCheckTest, EmptyArray) {
    std::vector<int> A = {};
    EXPECT_EQ(solution(A), 0) << "Empty array should not be recognized as a permutation";
}

// Test case for a single-element array
TEST_F(PermCheckTest, SingleElement) {
    std::vector<int> A = {1};
    EXPECT_EQ(solution(A), 1) << "Array {1} should be recognized as a permutation";
    
    std::vector<int> B = {5};
    EXPECT_EQ(solution(B), 0) << "Array {5} should not be recognized as a permutation";
}

// Test case for a large valid permutation
TEST_F(PermCheckTest, LargeValidPermutation) {
    std::vector<int> A(1000);
    for (int i = 0; i < 1000; i++) {
        A[i] = i + 1;
    }
    EXPECT_EQ(solution(A), 1) << "Array [1..1000] should be recognized as a permutation";
}

// Test case for a large invalid permutation
TEST_F(PermCheckTest, LargeInvalidPermutation) {
    std::vector<int> A(999);
    for (int i = 0; i < 999; i++) {
        A[i] = i + 1;
    }
    A.push_back(1001);  // Add an invalid element
    EXPECT_EQ(solution(A), 0) << "Array with range break should not be recognized as a permutation";
}
