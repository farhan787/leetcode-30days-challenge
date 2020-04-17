// Problem link: https://leetcode.com/problems/maximum-subarray/

// Time complexity => O(n); n = size of nums vector
// Space complexity => O(1)

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
        return INT_MIN;
    }

    int maxSumSoFar = nums[0];
    int currSum = nums[0];

    for (int i = 1; i < (int)nums.size(); ++i) {
        currSum = max(nums[i], nums[i] + currSum);
        maxSumSoFar = max(maxSumSoFar, currSum);
    }

    return maxSumSoFar;
}

int main() {
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << maxSubArray(nums1) << endl;
}
