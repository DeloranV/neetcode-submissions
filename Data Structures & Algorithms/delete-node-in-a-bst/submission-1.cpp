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
    TreeNode* findMax(TreeNode* root) {
        if (!root->right) return root;
        return findMax(root->right);
    }
    TreeNode* findMin(TreeNode* root) {
        if (!root->left) return root;
        return findMax(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (key == root->val) {
            if (!root->left && !root->right) return nullptr;
            else if (!root->left) {
                TreeNode* minRight = findMin(root->right);
                root->val = minRight->val;
                root->right = deleteNode(root->right, minRight->val);
            }
            else {
                TreeNode* maxLeft = findMax(root->left);
                root->val = maxLeft->val;
                root->left = deleteNode(root->left, maxLeft->val);
            }
            return root;
        }

        if (root->left && key < root->val) root->left = deleteNode(root->left, key);
        else if (root->right && key > root->val) root->right = deleteNode(root->right, key);

        return root;
    }
};