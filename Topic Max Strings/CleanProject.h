// CleanProject.h
#pragma once

#include <string>
#include <vector>

int solution(std::vector<std::string> &S, int K);
unsigned int LetterSequenceBasedBitmaskOf(
    const std::string &S,
    const std::string fullCharset = "abcdefghijklmnopqrstuvwxyz");
std::string getSortedLetterFrequency(const std::vector<std::string> &strings);
std::vector<std::string> removeDuplicateLetters(
    const std::vector<std::string> &input);
bool HasAtmostBitsSet(unsigned int num, unsigned int maxBits);