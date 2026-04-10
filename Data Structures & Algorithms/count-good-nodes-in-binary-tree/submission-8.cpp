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
    void countGoodNodes(TreeNode* root, int maxVal) {
        if (!root) return;
        if (root->val >= maxVal) {
            maxVal = root->val;
            max_counter++;
        }

        countGoodNodes(root->left, maxVal);
        countGoodNodes(root->right, maxVal);
    }

    int goodNodes(TreeNode* root) {
        countGoodNodes(root, std::numeric_limits<int>::min());
        return max_counter;
    }

private:
    int max_counter = 0;
};
