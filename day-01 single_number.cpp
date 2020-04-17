// Problem link: https://leetcode.com/problems/single-number

// Time complexity => O(n); n = size of nums vector
// Space complexity => O(1)

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int uniqueNum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        uniqueNum = uniqueNum ^ nums[i];
    }
    return uniqueNum;
}

int main() {
    vector<int> nums1 = {4, 1, 2, 1, 2};
    cout << singleNumber(nums1) << endl;
}
