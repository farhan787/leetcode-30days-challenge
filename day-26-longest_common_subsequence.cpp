// Problem link: https://leetcode.com/problems/longest-common-subsequence/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Time complexity = O(|text1| * |text2|)
// Space complexity = O(|text1| * |text2|)

int lcsHelper(string& text1, string& text2, int i, int j, vector<vector<int>>& dp) {
    if (i >= (int)text1.length() || j >= (int)text2.length()) {
        return 0;
    }

    if (dp[i][j] != 0) {
        return dp[i][j];
    }

    if (text1[i] == text2[j]) {
        return dp[i][j] = lcsHelper(text1, text2, i + 1, j + 1, dp) + 1;
    }

    int lcs1 = lcsHelper(text1, text2, i + 1, j, dp);
    int lcs2 = lcsHelper(text1, text2, i, j + 1, dp);
    return dp[i][j] = max(lcs1, lcs2);
}

int longestCommonSubsequence(string text1, string text2) {
    int i = 0;
    int j = 0;

    vector<vector<int>> dp((int)text1.length(), vector<int>((int)text2.length(), 0));
    return lcsHelper(text1, text2, i, j, dp);
}

int main() {
}
