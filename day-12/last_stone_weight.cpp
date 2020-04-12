// Problem link: https://leetcode.com/problems/last-stone-weight/

// Time complexity = O(n log n) ; where n = size of stones vector
// Space complexity = O(n)

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxHeap;
    for (int stone : stones) {
        maxHeap.push(stone);
    }

    while ((int)maxHeap.size() > 1) {
        int stone1 = maxHeap.top();
        maxHeap.pop();
        int stone2 = maxHeap.top();
        maxHeap.pop();

        int stoneLeft = abs(stone1 - stone2);
        if (stoneLeft > 0) {
            maxHeap.push(stoneLeft);
        }
    }

    return !maxHeap.empty() ? maxHeap.top() : 0;
}

int main() {
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << lastStoneWeight(stones) << endl;
}
