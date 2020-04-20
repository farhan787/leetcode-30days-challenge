// Problem link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Time complexity = O(n); n = preorder.size()
// Space complexity = O(n)
TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = NULL;
    if (preorder.empty()) {
        return root;
    }

    root = new TreeNode(preorder[0]);

    stack<TreeNode*> stk;
    stk.push(root);

    for (int i = 1; i < (int)preorder.size(); i++) {
        TreeNode* newNode = new TreeNode(preorder[i]);

        if (!stk.empty() && preorder[i] < stk.top()->val) {
            stk.top()->left = newNode;
        } else {
            TreeNode* parent = stk.top();
            while (!stk.empty() && preorder[i] > stk.top()->val) {
                parent = stk.top();
                stk.pop();
            }

            parent->right = newNode;
        }
        stk.push(newNode);
    }

    return root;
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode* root = bstFromPreorder(preorder);
}
