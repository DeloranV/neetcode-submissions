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
        std::vector<std::vector<int>> result;
        std::queue<TreeNode*> q1;

        if(root) q1.push(root);

        while (q1.size() > 0) {
            result.push_back({});
            auto curr_size = q1.size();
            while (curr_size > 0) {
                auto elem = q1.front();
                q1.pop();
                result.back().push_back({elem->val});
                if (elem->left) q1.push(elem->left);
                if (elem->right) q1.push(elem->right);
                --curr_size;
            }
        }
        return result;
    }
};
