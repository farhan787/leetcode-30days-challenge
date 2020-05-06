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

#include <limits.h>

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Abstracted by LeetCode
class BinaryMatrix {
   public:
    vector<int> dimensions();
    int get(int row, int col);
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

// Non-trivial Optimized Binary Search approach
// Time complexity = O(|row| * log|col|)
// Space Complexity = O(1)
int binarySearch(BinaryMatrix& binaryMatrix, int row, int start_index, int end_index) {
    int index_of_1 = -1;
    while (start_index <= end_index) {
        int mid = start_index + (end_index - start_index) / 2;
        int num = binaryMatrix.get(row, mid);

        if (num == 1) {
            index_of_1 = mid;
            end_index = mid - 1;
        } else {
            start_index = mid + 1;
        }
    }
    return index_of_1;
}

int leftMostColumnWithOne(BinaryMatrix& binaryMatrix) {
    int left_most_index = -1;

    vector<int> dimensions = binaryMatrix.dimensions();
    const int row = dimensions[0];
    const int col = dimensions[1];
    const int searchStartIndex = 0;

    int search_end_index = col - 1;
    for (int i = 0; i < row; i++) {
        int index_of_1 = binarySearch(binaryMatrix, i, searchStartIndex, search_end_index);

        if (index_of_1 != -1) {
            left_most_index = index_of_1;

            // for next rows, we'll search for 1 only before the current index of 1
            search_end_index = left_most_index - 1;
        }

        if (search_end_index < col - 1 && i + 1 < row && col - 1 > 0) {
            int next_row_num = binaryMatrix.get(i + 1, col - 1);
            if (next_row_num == 0) {
                // we can skip the next row because
                // it doesn't have a 1 in it before the current column or search_end_index
                i++;
            }
        }
    }

    return left_most_index;
}

int main() {
}
