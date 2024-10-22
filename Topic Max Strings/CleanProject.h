// CleanProject.h
#pragma once

#include <string>
#include <vector>

int solution(std::vector<std::string> &S, int K);
int NumBuildable(const std::vector<std::string> &A, std::string S);
uint LetterSequenceBasedBitmaskOf(
    const std::string &S,
    const std::string fullCharset = "abcdefghijklmnopqrstuvwxyz");
std::string getSortedLetterFrequency(const std::vector<std::string> &strings);
std::vector<std::string> removeDuplicateLetters(
    const std::vector<std::string> &input);
bool HasAtmostBitsSet(uint num, uint maxBits);