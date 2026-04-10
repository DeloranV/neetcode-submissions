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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        bool leftValid = isValidBST(root->left);
        if (root->val <= last_val) return false;
        last_val = root->val;
        bool rightValid = isValidBST(root->right);

        return leftValid && rightValid;
    }

private:
    int last_val = std::numeric_limits<int>::min();
};
