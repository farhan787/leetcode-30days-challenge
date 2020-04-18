// Problem link: https://leetcode.com/problems/contiguous-array

// Time complexity = O(n) ; where n = size of nums
// Space complexity = O(n)

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int findMaxLength(vector<int>& nums) {
    int maxLen = INT_MIN;

    // map: (key->count, value->index)
    unordered_map<int, int> map;

    int count = 0;
    int initialIndex = -1;
    map.insert({count, initialIndex});

    for (int i = 0; i < (int)nums.size(); ++i) {
        int num = nums[i];
        count += (num == 0) ? (-1) : 1;

        if (map.find(count) != map.end()) {
            int currLen = i - map[count];
            maxLen = max(maxLen, currLen);
        } else {
            map.insert({count, i});
        }
    }

    return (maxLen != INT_MIN) ? maxLen : 0;
}

int main() {
    vector<int> nums = {0, 1, 1, 0, 1, 0, 0, 1, 1, 1};
    cout << findMaxLength(nums) << endl;
}
