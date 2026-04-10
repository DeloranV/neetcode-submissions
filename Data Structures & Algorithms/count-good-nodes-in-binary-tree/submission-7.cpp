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
    void countGoodNodes(TreeNode* root, int maxValue) {
        if (!root) return;
        if (root->val >= maxValue) {
            maxValue = root->val;
            max_counter_++;
        }
        countGoodNodes(root->left, maxValue);
        countGoodNodes(root->right, maxValue);
    }

    int goodNodes(TreeNode* root) {
        countGoodNodes(root, root->val);
        return max_counter_;
    }

private:
    int max_counter_ = 0;
};
