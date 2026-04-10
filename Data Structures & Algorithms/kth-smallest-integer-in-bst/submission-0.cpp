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
    void getSmallest(TreeNode* root, int k) {
        if (!root) return;

        getSmallest(root->left, k);
        if (++counter_ == k) kthSmallest_ = root->val;
        getSmallest(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        getSmallest(root, k);
        return kthSmallest_;
    }

private:
    int counter_ = 0;
    int kthSmallest_;
};
