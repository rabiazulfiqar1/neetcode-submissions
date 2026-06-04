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

class Codec {
public:
    void serializeHelper(TreeNode* root, string &out) {
        if (!root) {
            out += "N,";
            return;
        }

        out += to_string(root->val) + ",";
        serializeHelper(root->left, out);
        serializeHelper(root->right, out);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        serializeHelper(root, str);
        return str;
    }

    TreeNode* buildTree(vector<string> &nodes, int &i) {
        if (i >= nodes.size() || nodes[i] == "N") {
            i++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(nodes[i]));
        i++;

        root->left = buildTree(nodes, i);
        root->right = buildTree(nodes, i);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp = "";

        // split by comma
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        int i = 0;
        return buildTree(nodes, i);
    }
};
