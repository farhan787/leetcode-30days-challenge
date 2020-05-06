// Problem link: https://leetcode.com/problems/subarray-sum-equals-k

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Time complexity = O(n) ; n = size of nums
// Space complexity = O(n)
int subarraySum(vector<int>& nums, int k) {
    int max_sub_arrays = 0;
    int curr_sum = 0;

    unordered_map<int, int> map;

    for (int i = 0; i < (int)nums.size(); i++) {
        int num = nums[i];
        curr_sum += num;

        if (curr_sum == k) {
            ++max_sub_arrays;
        }

        if (map[curr_sum - k]) {
            max_sub_arrays += map[curr_sum - k];
        }
        map[curr_sum]++;
    }

    return max_sub_arrays;
}

int main() {
}
