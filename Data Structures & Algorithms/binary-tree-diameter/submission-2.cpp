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
    int countDiam(TreeNode* root) {
        if (!root) return -1;

        int leftLen = countDiam(root->left) + 1;
        int rightLen = countDiam(root->right) + 1;

        max_ = std::max(max_, leftLen + rightLen);

        return std::max(leftLen, rightLen);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        countDiam(root);
        return max_;
    }

private:
    int max_ = std::numeric_limits<int>::min();
};
