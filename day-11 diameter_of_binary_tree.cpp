// Problem link: https://leetcode.com/problems/diameter-of-binary-tree

#include <iostream>
#include <vector>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Time complexity = O(total number of nodes in tree) or O(height of tree)
// Space complexity = O(total number of nodes in tree) or O(height of tree)

class Solution {
   public:
    class Pair {
       public:
        int height;
        int diameter;

        Pair() {
            this->height = 0;
            this->diameter = 0;
        }
    };

    Pair diameterOfBinaryTreeHelper(TreeNode* root) {
        Pair currPair;

        if (root == NULL) {
            currPair.diameter = currPair.height = 0;
            return currPair;
        }

        Pair leftPair = diameterOfBinaryTreeHelper(root->left);
        Pair rightPair = diameterOfBinaryTreeHelper(root->right);

        int leftDiameter = leftPair.diameter;
        int rightDiameter = rightPair.diameter;
        int rootDiameter = leftPair.height + rightPair.height;

        currPair.diameter = max(rootDiameter, max(leftDiameter, rightDiameter));
        currPair.height = max(leftPair.height, rightPair.height) + 1;

        return currPair;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        Pair pair = diameterOfBinaryTreeHelper(root);
        return pair.diameter;
    }
};

int main() {
}
