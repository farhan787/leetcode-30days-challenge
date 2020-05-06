// Problem link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;
};

const int INF = 1e9 + 5;

// Time complexity = O(n) ; n = number of nodes in tree
// Space complexity = O(height of tree)
int pathSum(TreeNode* root, int& currMaxSum) {
    if (root == NULL) {
        return 0;
    }

    int leftSum = max(0, pathSum(root->left, currMaxSum));
    int rightSum = max(0, pathSum(root->right, currMaxSum));

    currMaxSum = max({currMaxSum, leftSum + root->val + rightSum});
    return max(leftSum, rightSum) + root->val;
}

int maxPathSum(TreeNode* root) {
    int currMaxSum = INT_MIN;
    int sum = pathSum(root, currMaxSum);
    return currMaxSum;
}

int main() {
}
