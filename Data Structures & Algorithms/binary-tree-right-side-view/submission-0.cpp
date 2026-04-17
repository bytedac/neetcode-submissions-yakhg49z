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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            int size = queue.size();   // curr lyer
            for (int i = 0; i < size; i++) {
                TreeNode* curr = queue.front();
                queue.pop();
                
                if (i == size - 1) {
                    res.push_back(curr->val);
                }

                if (curr->left) queue.push(curr->left);
                if (curr->right) queue.push(curr->right);
            }
        }
        return res;
    }
};