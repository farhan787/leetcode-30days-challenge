// Problem link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

// Time complexity => O(n); n = size of prices vector
// Space complexity => O(1)

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int profit = 0;
    for (int i = 0; i < (int)prices.size() - 1; ++i) {
        if (prices[i + 1] > prices[i]) {
            profit += prices[i + 1] - prices[i];
        }
    }
    return profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
}
