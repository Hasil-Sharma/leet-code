// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

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
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size()){
            root = q.front();
            q.pop();
            ss << (root ? to_string(root->val) + " ": "# ");
            if (root){
                q.push(root->left);
                q.push(root->right);
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        queue<string> tokens;
        string buff;
        while (ss >> buff)
            tokens.push(buff);
        TreeNode *root = str2Node(tokens.front());
        tokens.pop();
        queue<TreeNode*> q;
        q.push(root);
        while(tokens.size()){
            auto front = q.front();
            q.pop();
            front->left = str2Node(tokens.front());
            tokens.pop();
            front->right = str2Node(tokens.front());
            tokens.pop();
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        return root;
    }
    
    TreeNode *str2Node(string s){
        if (s.length() == 0 || s == "#") return NULL;
        int val = stoi(s);
        return new TreeNode(val);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
