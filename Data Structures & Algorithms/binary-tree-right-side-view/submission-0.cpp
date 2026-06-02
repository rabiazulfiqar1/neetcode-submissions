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
        if (root == NULL) return {};
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            while (s>1) {
                TreeNode* node = q.front();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
                s--;
            }
            TreeNode* rightmost = q.front();
            ans.push_back(rightmost->val);
            if (rightmost->left) q.push(rightmost->left);
            if (rightmost->right) q.push(rightmost->right);
            q.pop();
        }
        return ans;
    }
};
