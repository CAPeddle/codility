

#include <vector>
#include <algorithm>
#include <numeric>

long long count_until(int n)
{
    return static_cast<long long>(n) * (n + 1) / 2;
}

int solution(std::vector<int> &A)
{  
    if (A.empty()) return 0;

    // Handle single element case - it's a permutation only if it's 1
    if (A.size() == 1)
        return (A[0] == 1) ? 1 : 0;

    auto predictedSum = count_until(A.size());
    auto actualSum = std::accumulate(A.begin(), A.end(), 0);

   return (predictedSum == actualSum) ? 1 : 0;
}