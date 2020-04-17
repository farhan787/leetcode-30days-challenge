// Problem link: https://leetcode.com/problems/happy-number

// Time complexity => O(k * log n)
// where, k = number of iterations to find the cycle(or get a repeated number) or to get a 1
// log n = to get the next number, since there are max log n digits in a number

// Space complexity => O(k)

// By doing mathematical analysis we find that the number of iterations to find a cycle or get a 1,
// it won't take more than 50 iterations at worst case, that's why `k` can be considered as constant. So,

// Time complexity => O(log n)
// Space complexity => O(1)

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int getNextNumber(int number) {
    int nextNumber = 0;

    while (number > 0) {
        int lastDigit = number % 10;
        nextNumber = nextNumber + (lastDigit * lastDigit);
        number = number / 10;
    }
    return nextNumber;
}

bool isHappy(int n) {
    unordered_set<int> seenNumbers;

    while (n != 1) {
        seenNumbers.insert(n);

        int nextNumber = getNextNumber(n);

        bool isNextNumberAlreadySeen = seenNumbers.find(nextNumber) != seenNumbers.end();
        if (isNextNumberAlreadySeen) {
            return false;
        }

        n = nextNumber;
    }
    return true;
}

// Solution 2:
// More advanced solution and for explanation visit the below link,
// https://leetcode.com/problems/happy-number/discuss/565692/C%2B%2B-0ms-O(n)-time-and-O(1)-space-with-in-depth-intuitive-explanation

// no extra space
bool isHappy_advanced(int n) {
    int slow = n;
    int fast = getNextNumber(n);

    while (slow != fast) {
        slow = getNextNumber(slow);

        fast = getNextNumber(fast);
        fast = getNextNumber(fast);
    }

    return slow == 1;
}

int main() {
    int num1 = 19;
    cout << isHappy(num1) << endl;
}
