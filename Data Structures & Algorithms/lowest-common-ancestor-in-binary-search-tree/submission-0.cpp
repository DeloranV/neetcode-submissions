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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        min_ = std::min(p->val, q->val);
        max_ = std::max(p->val, q->val);

        if (root->val >= min_ && root->val <= max_) return root;

        if (root->val > max_) return lowestCommonAncestor(root->left, p, q);
        else if (root->val < min_) return lowestCommonAncestor(root->right, p, q);
        

    }
    
private:
    int min_ = std::numeric_limits<int>::max();
    int max_ = std::numeric_limits<int>::min();
};
