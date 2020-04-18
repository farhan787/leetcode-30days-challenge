// Problem statement:
// Given an integer array arr, count element x such that x + 1 is also in arr.
// If there're duplicates in arr, count them seperately.

// Input: arr = [1,3,2,3,5,0], output = 3
// Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.

// Input: arr = [1,1,2,2], output = 2
// Explanation: Two 1s are counted cause 2 is in arr.

// Constraints:
// 1 <= arr.length <= 1000
// 0 <= arr[i] <= 1000

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Time complexity = O(n); n = size of arr vector
// Space complexity = O(n)

int countElements(vector<int>& arr) {
    unordered_set<int> set;
    for (int num : arr) {
        set.insert(num);
    }

    int elementsCount = 0;
    for (int i = 0; i < (int)arr.size(); ++i) {
        int num = arr[i];
        if (set.find(num + 1) == set.end()) {
            continue;
        }
        ++elementsCount;
    }
    return elementsCount;
}

int main() {
    vector<int> arr = {1, 3, 2, 3, 5, 0};
    cout << countElements(arr) << endl;
}
