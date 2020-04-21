// Challenge Link: https://leetcode.com/explore/featured/card/30-day-leetcoding-challenge/530/week-3/3306/
// to see visual examples, and understand the problem in a more better way

// Problem Statement:
// (This problem is an interactive problem.)
// A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in non-decreasing order.

// Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. If such index doesn't exist, return -1.
// You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:

// BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
// BinaryMatrix.dimensions() returns a list of 2 elements [n, m], which means the matrix is n * m.
// Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions that attempt to circumvent the judge will result in disqualification.

// For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not have access the binary matrix directly.

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class BinaryMatrix {
    // Abstracted by LeetCode
};

// Time Complexity = O(|row| + |col|)
// Space Complexity = O(1)
int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
    int left_most_col_index = INT_MAX;

    vector<int> dimensions = binaryMatrix.dimensions();
    const int row = dimensions[0];
    const int col = dimensions[1];

    int row_pointer = 0;
    int col_pointer = col - 1;
    while (row_pointer >= 0 && col_pointer >= 0 && row_pointer < row && col_pointer < col) {
        int curr_num = binaryMatrix.get(row_pointer, col_pointer);

        if (curr_num == 1) {
            left_most_col_index = min(left_most_col_index, col_pointer);
            --col_pointer;
        } else {
            ++row_pointer;
        }
    }

    return (left_most_col_index == INT_MAX) ? -1 : left_most_col_index;
}

int main() {
    return 0;
}
