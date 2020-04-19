// Problem link: https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Time complexity = O(log n); n = nums.size()
// Space complexity = O(1)
int getPivotIndex(vector<int>& nums) {
    int left = 0;
    int right = (int)nums.size() - 1;
    int endIndex = (int)nums.size() - 1;

    int pivotIndex = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= nums[endIndex]) {
            pivotIndex = mid;
            right = mid - 1;
        }

        else if (nums[mid] >= nums[endIndex]) {
            left = mid + 1;
        }
    }
    return pivotIndex;
}

int binarySearch(vector<int>& nums, int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int pivotIndex = getPivotIndex(nums);
    if (pivotIndex == -1) return -1;

    int left = 0;
    int right = nums.size() - 1;
    int targetIndex = -1;

    if (pivotIndex == 0) {
        return binarySearch(nums, left, right, target);
    }

    if (target < nums[0]) {
        left = pivotIndex;
    } else {
        right = pivotIndex - 1;
    }

    targetIndex = binarySearch(nums, left, right, target);
    return targetIndex;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << search(nums, target) << endl;
}
