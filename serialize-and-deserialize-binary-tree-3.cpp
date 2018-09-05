/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    
private:
    void preOrder(TreeNode* root, stringstream& ss){
        if (!root) ss << "# ";
        else {
            ss << to_string(root->val) << " ";
            preOrder(root->left, ss);
            preOrder(root->right, ss);
        }
    }
    
    TreeNode* dpreOrder(stringstream& ss){
        string buff;
        if (ss >> buff){
            TreeNode* root = (buff == "#") ? NULL : new TreeNode(stoi(buff));
            if (root){
                root->left = dpreOrder(ss);
                root->right = dpreOrder(ss);
            }
            return root;
        }
        return NULL;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        preOrder(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return dpreOrder(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
