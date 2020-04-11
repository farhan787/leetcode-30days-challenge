// Problem link: https://leetcode.com/problems/backspace-string-compare

// Time complexity => O(|S| + |T|)
// Space complexity => O(1)

#include <iostream>
#include <vector>
using namespace std;

void movePointerToValidChar(string& str, int& pointer, int& charSkip) {
    while (pointer >= 0) {
        if (str[pointer] == '#') {
            --pointer;
            ++charSkip;
        } else if (charSkip > 0) {
            --pointer;
            --charSkip;
        } else break;
    }
}

bool backspaceCompare(string S, string T) {
    int sPointer = (int)S.length() - 1;
    int tPointer = (int)T.length() - 1;

    int sSkip = 0;
    int tSkip = 0;

    while (sPointer >= 0 || tPointer >= 0) {
        movePointerToValidChar(S, sPointer, sSkip);
        movePointerToValidChar(T, tPointer, tSkip);

        if (sPointer >= 0 && tPointer >= 0 && S[sPointer] != T[tPointer]) {
            return false;
        }

        if ((sPointer >= 0) != (tPointer >= 0)) {
            return false;
        }

        --sPointer;
        --tPointer;
    }
    return true;
}

int main() {
    string S = "ab#c";
    string T = "ad#c";
    cout << backspaceCompare(S, T) << endl;
}
