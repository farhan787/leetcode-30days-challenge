// Problem link: https://leetcode.com/problems/jump-game/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Time complexity = O(n) ; n = size of nums
// Space complexity = O(1)
bool canJump(vector<int>& nums) {
    int last_good_index = (int)nums.size() - 1;
    for (int i = (int)nums.size() - 1; i >= 0; i--) {
        if (i + nums[i] >= last_good_index) {
            last_good_index = i;
        }
    }
    return last_good_index == 0;
}

int main() {
}
