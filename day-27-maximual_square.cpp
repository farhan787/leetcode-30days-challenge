// Problem link: http://leetcode.com/problems/maximal-square

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// row = matrix.size(); col = matrix[0].size()

// Time complexity = O(row * col)
// Space complexity = O(row * col)
int maximalSquare(vector<vector<char>>& matrix) {
    int maxLen = 0;

    if (matrix.empty() || matrix[0].empty()) {
        return 0;
    }

    vector<vector<int>> dp((int)matrix.size(), vector<int>((int)matrix[0].size(), 0));

    for (int row = 0; row < (int)matrix.size(); row++) {
        for (int col = 0; col < (int)matrix[0].size(); col++) {
            if (matrix[row][col] == '1') {
                dp[row][col] = 1;
                if (row > 0 && col > 0) {
                    dp[row][col] += min({dp[row][col - 1], dp[row - 1][col], dp[row - 1][col - 1]});
                }
                maxLen = max(maxLen, dp[row][col]);
            }
        }
    }
    int squreArea = maxLen * maxLen;
    return squreArea;
}

int main() {
}
