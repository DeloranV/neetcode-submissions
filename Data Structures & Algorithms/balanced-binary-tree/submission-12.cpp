/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int countDiff(TreeNode* root) {
        if (!root) return -1;

        int leftHeight = countDiff(root->left) + 1;
        int rightHeight = countDiff(root->right) + 1;

        if (std::abs(leftHeight - rightHeight) > 1) treeBalanced = false;

        return std::max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        countDiff(root);
        return treeBalanced;
    }

private:
    bool treeBalanced = true;
};
