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
    bool dfs(TreeNode* root, pair<int, int> p) {
        if (root == NULL) return true;
        if (! (root->val > p.first && root->val < p.second)) return false;
        return dfs(root->left, {p.first, root->val}) && dfs(root->right, {root->val, p.second});
    }
public:
    bool isValidBST(TreeNode* root) {
        pair<int, int> p = {INT_MIN, INT_MAX};
        return dfs(root, p);
    }
};
