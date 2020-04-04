// Problem link: https://leetcode.com/problems/move-zeroes

// Time complexity => O(n); where n = size of nums vector
// Space complexity => O(1)

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// to print a 1-d vector
void printVec(vector<int>& vec) {
    for (int num: vec) {
        cout << num << ", ";
    }
    cout << endl;
}

void moveZeroes(vector<int>& nums) {
    int zeroPointer = 0;
    while (zeroPointer < (int)nums.size() && nums[zeroPointer] != 0) {
        ++zeroPointer;
    }

    int currIndex = 0;
    while (currIndex < (int)nums.size()) {
        int num = nums[currIndex];

        if (num != 0 && zeroPointer < currIndex) {
            swap(nums[zeroPointer], nums[currIndex]);

            while (zeroPointer < (int)nums.size() && nums[zeroPointer] != 0) {
                ++zeroPointer;
            }
        }
        ++currIndex;
    }
}

int main() {
    vector<int> nums1 = {0, 1, 0, 3, 12};

    printVec(nums1);
    moveZeroes(nums1);
    printVec(nums1);
}
