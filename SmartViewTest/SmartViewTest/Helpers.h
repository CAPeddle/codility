#pragma once

#include <iostream>

void AssertTrue(bool OK)
{
    if (OK)
    {
        std::cout << "Test SUCCESS" << std::endl;
    }
    else
    {
        std::cout << "Test FAILED" << std::endl;
    }
}

void AssertSetEqual(const std::set<size_t>& expected, const std::set<size_t>& received)
{
    bool OK = true;
    for (auto& e : expected)
    {
        if (received.count(e) != 1)
        {
            std::cout << "Expected " << e << " but was not received" << std::endl;
            OK = false;
        }
    }

    for (auto& e : received)
    {
        if (expected.count(e) != 1)
        {
            std::cout << "Received " << e << " but was not expected" << std::endl;
            OK = false;
        }
    }

    AssertTrue(OK);
}