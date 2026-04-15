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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> queue;
        if (!root) return res;
        queue.push(root);
        while (!queue.empty()) {
            int n = queue.size();
            vector<int> temp(n);
            for (int i = 0; i < n; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                temp[i] = node->val;
                
                if (node->left) queue.push(node->left);
                if (node->right) queue.push(node->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
