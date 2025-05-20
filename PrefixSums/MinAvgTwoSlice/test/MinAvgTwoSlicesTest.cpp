#include <gtest/gtest.h>

#include "MinAvgTwoSlices.h"

class MinAvgTwoSlicesTest : public ::testing::Test {
protected:
    MinAvgTwoSlices* islands;

    void SetUp() override {
        // Using 10 second time limit
        islands = new MinAvgTwoSlices();
    }

    void TearDown() override {
        delete islands;
    }
};

TEST_F(MinAvgTwoSlicesTest, TestMessageSequence) {
    
    std::vector<std::vector<std::string>> matrix = {
        {"x", "x", ".", ".", ".", "."},
        {"x", "x", ".", ".", ".", "."},
        {".", ".", "x", ".", ".", "."},
        {"x", ".", ".", "x", "x", "."},
        {"x", ".", "x", ".", "x", "."},
        {"x", "x", "x", ".", ".", "."}
    };
    EXPECT_EQ(4, MinAvgTwoSlices::countIslands(matrix));


    std::vector<std::vector<std::string>> matrix2 = {
        {".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", "."},
        {".", ".", ".", ".", ".", "."}
    };
    EXPECT_EQ(0, MinAvgTwoSlices::countIslands(matrix2));

    std::vector<std::vector<std::string>> matrix3 = {
        {"x", ".", ".", ".", ".", "."},
        {".", "x", ".", ".", ".", "."},
        {".", ".", "x", ".", ".", "."},
        {".", ".", ".", "x", ".", "."},
        {".", ".", ".", ".", "x", "."},
        {".", ".", ".", ".", ".", "x"}
    };
    EXPECT_EQ(6, MinAvgTwoSlices::countIslands(matrix3));

    std::vector<std::vector<std::string>> matrix4 = {
        {"x", "x", "x", "x", "x", "x"},
        {"x", "x", "x", "x", "x", "x"},
        {"x", "x", "x", "x", "x", "x"},
        {"x", "x", "x", "x", "x", "x"},
        {"x", "x", "x", "x", "x", "x"},
        {"x", "x", "x", "x", "x", "x"}
    };
    EXPECT_EQ(1, MinAvgTwoSlices::countIslands(matrix4));


    std::vector<std::vector<std::string>> matrix5 = {
        {"x", ".", "x", "x", "x", "."},
        {"x", ".", ".", ".", "x", "."},
        {"x", ".", "x", ".", "x", "x"},
        {"x", "x", "x", ".", "x", "."},
        {".", ".", ".", "x", "x", "."},
        {".", ".", ".", ".", ".", "."}
    };

    EXPECT_EQ(2, MinAvgTwoSlices::countIslands(matrix5));
}
