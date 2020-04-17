// Problem link: https://leetcode.com/problems/valid-parenthesis-string

#include <iostream>
#include <vector>
using namespace std;

// Time complexity = O(n); where n = s.length()
// Space complexity = O(1)
bool checkValidString(string s) {
    int balance = 0;

    for (int i = 0; i < (int)s.length(); i++) {
        char ch = s[i];

        if (ch == '(' || ch == '*') {
            balance++;
        } else if (--balance == -1) {
            return false;
        }
    }

    balance = 0;
    for (int i = (int)s.length() - 1; i >= 0; i--) {
        char ch = s[i];

        if (ch == ')' || ch == '*') {
            balance++;
        } else if (--balance == -1) {
            return false;
        }
    }

    return true;
}

int main() {
    string str = "((*)))***))(";
    cout << checkValidString(str) << endl;
}
