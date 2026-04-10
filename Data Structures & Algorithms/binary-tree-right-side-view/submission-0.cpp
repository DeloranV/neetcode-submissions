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
#include <queue>

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::queue<TreeNode*> que;
        std::vector<std::vector<int>> levels;
        std::vector<int> result;

        if (root) {
            que.push(root);
            result.push_back(root->val);
        } 

        while (que.size() > 0) {
            auto curr_size = que.size();
            levels.push_back({});
            while (curr_size > 0) {
                auto elem = que.front();
                que.pop();
                --curr_size;
                if (elem->left) {
                    levels.back().push_back(elem->left->val);
                    que.push(elem->left);
                } 
                if (elem->right) {
                    levels.back().push_back(elem->right->val);
                    que.push(elem->right);
                } 
            }
        }
        for (auto& level : levels) {
            if(level.size() > 0) result.push_back(level.back());
        }
        return result;
    }
};
