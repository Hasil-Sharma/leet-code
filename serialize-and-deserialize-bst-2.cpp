// https://leetcode.com/problems/serialize-and-deserialize-bst/description/

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
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        stringstream ss;
        shelper(root, ss);
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preOrder;
        stringstream ss(data);
        string token;
        int idx = 0;
        while(ss >> token)
            preOrder.push_back(stoi(token));
        
        return dhelper(preOrder, idx, INT_MIN, INT_MAX);
    }

private:
    void shelper(TreeNode* root, stringstream& ss){
        if (!root) return ;
        shelper(root->left, ss);
        shelper(root->right, ss);
    }
    
    TreeNode* dhelper(vector<int>& preOrder, int& idx, int min, int max){
        TreeNode* root = NULL;
        if (idx >= preOrder.size()) return root;
        else if (preOrder[idx] >= min && preOrder[idx] <= max){
            // cout << preOrder[idx] << endl;
            root = new TreeNode(preOrder[idx++]);
            root->left = dhelper(preOrder, idx, min, root->val);
            root->right = dhelper(preOrder, idx, root->val, max);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
