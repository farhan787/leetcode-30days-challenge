// Problem link: https://leetcode.com/problems/bitwise-and-of-numbers-range/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Time complexity = O(n) if m == 1 then it'd run for n times
// Space complexity = O(1)
int rangeBitwiseAnd(int m, int n) {
    while (n > m) {
        n = n & (n - 1);
    }
    return n;
}

int main() {
}
