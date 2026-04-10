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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};

        std::vector<std::vector<int>> result {};
        std::queue<TreeNode*> q1 {};
        auto q1_size = 1;
        q1.push(root);

        while (q1_size > 0) {
            result.push_back({});
            auto curr_size = q1_size;
            while (curr_size > 0) {
                auto elem = q1.front();
                q1.pop();
                --q1_size;
                result.back().push_back({elem->val});
                --curr_size;
                if (elem->left) {
                    q1.push(elem->left);
                    ++q1_size;
                } 
                if (elem->right) {
                    q1.push(elem->right);
                    ++q1_size;
                }
            }
        }
        return result;
    }
};
