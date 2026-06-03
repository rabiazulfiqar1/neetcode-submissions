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
    unordered_map<int, int> mp;
public:
    void fill_map(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
    }
    TreeNode* returnTree(vector<int>& preorder, vector<int>& inorder, int preL, int preR, int inL, int inR) {
        if (preL > preR || inL > inR) return NULL;
        TreeNode* root = new TreeNode(preorder[preL]);
        int mid = mp[preorder[preL]];
        int leftSize = mid-inL;
        root->left = returnTree(preorder, inorder, preL+1, preL+leftSize, inL, mid-1);
        root->right = returnTree(preorder, inorder, preL+leftSize+1, preR, mid+1, inR);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        fill_map(preorder, inorder);
        return returnTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
