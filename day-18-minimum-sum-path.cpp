// Problem link: https://leetcode.com/problems/minimum-path-sum

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Time complexity = O(m * n)
// Space complexity = O(m * n)
// Both solutions have same time and space complexity

// Top Down DP
int getMinPathSum(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& dp) {
    if (row == (int)grid.size() - 1 && col == (int)grid[0].size() - 1) {
        return grid[row][col];
    }

    if (row < 0 || col < 0 || row >= (int)grid.size() || col >= (int)grid[0].size()) {
        return INT_MAX;
    }

    if (dp[row][col] != -1) {
        return dp[row][col];
    }

    int rightSum = getMinPathSum(grid, row, col + 1, dp);
    int downSum = getMinPathSum(grid, row + 1, col, dp);

    int minSum = min(rightSum, downSum) + grid[row][col];
    return dp[row][col] = minSum;
}

int minPathSumTopDown(vector<vector<int>>& grid) {
    vector<vector<int>> dp((int)grid.size(), vector<int>((int)grid[0].size(), -1));

    int row = 0;
    int col = 0;

    return getMinPathSum(grid, row, col, dp);
}

// Bottom Up DP
int minPathSumBottomUp(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    // initialize 2-d vector with 0 of same size as grid
    vector<vector<int>> dp((int)grid.size(), vector<int>((int)grid[0].size(), 0));
    const int LAST_ROW = (int)grid.size() - 1;
    const int LAST_COL = (int)grid[0].size() - 1;

    int initSum = 0;
    for (int col = 0; col <= LAST_COL; col++) {
        // fill first row
        dp[0][col] += initSum + grid[0][col];
        initSum = dp[0][col];
    }

    initSum = dp[0][0];
    for (int row = 1; row <= LAST_ROW; row++) {
        // fill first col
        dp[row][0] += initSum + grid[row][0];
        initSum = dp[row][0];
    }

    for (int row = 1; row <= LAST_ROW; row++) {
        for (int col = 1; col <= LAST_COL; col++) {
            dp[row][col] = min(dp[row][col - 1], dp[row - 1][col]) + grid[row][col];
        }
    }

    return dp[LAST_ROW][LAST_COL];
}

int main() {
    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1},
    };
    // initialise the grid yourself or go to problem link at the top of this page ⬆︎⬆︎⬆︎
    cout << minPathSumBottomUp(grid) << endl;
}
