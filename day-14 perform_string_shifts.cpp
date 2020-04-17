// Problem statement:
// You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

// direction can be 0 (for left shift) or 1 (for right shift).
// amount is the amount by which string s is to be shifted.
// A left shift by 1 means remove the first character of s and append it to the end.
// Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
// Return the final string after all operations.

// Example
// Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
// Output: "efgabcd"
// Explanation:
// [1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
// [1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
// [0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
// [1,3] means shift to right by 3. "abcdefg" -> "efgabcd"

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Time complexity = O(n); n = size of shift vector
// Space complexity = O(n); for the substring operation

int getNetShift(string& s, vector<vector<int>>& shifts) {
    const int LEFT = 0;
    int netShift = 0;

    for (vector<int>& shf : shifts) {
        int direction = shf[0];
        int amount = shf[1];

        if (direction == LEFT) {
            netShift -= amount;
        } else {
            netShift += amount;
        }
    }

    // to make sure that netShift is not greater than s.length()
    // if that happens then s.substr(i, j) will throw runtime error
    netShift %= (int)s.length();
    return netShift;
}

string getShiftedString(string& s, int netShift) {
    string shiftedStr = s;

    if (netShift == 0) {
        return shiftedStr;
    }

    int sLen = (int)s.length();
    if (netShift > 0) {
        shiftedStr = s.substr(sLen - netShift) + s.substr(0, sLen - netShift);
    } else if (netShift < 0) {
        netShift = -netShift;
        shiftedStr = s.substr(netShift) + s.substr(0, netShift);
    }

    return shiftedStr;
}

// Intuition: You may notice that left shift cancels the right shift, so count the total left shift times
// (may be negative if the final result is right shift), and perform it once.
string stringShift(string s, vector<vector<int>>& shift) {
    int netShift = getNetShift(s, shift);
    string shiftedStr = getShiftedString(s, netShift);

    return shiftedStr;
}

int main() {
    string str = "abcdefg";
    vector<vector<int>> shift = {{1, 1}, {1, 1}, {0, 2}, {1, 3}};
    cout << stringShift(str, shift) << endl;
}
