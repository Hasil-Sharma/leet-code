// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

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
        queue<TreeNode*> q;
        stringstream ss;
        
        q.push(root);
        
        while(q.size()){
            root = q.front();
            q.pop();
            
            if(!root){
                ss << "# ";
                continue;
            }
            
            ss << to_string(root->val) << " ";
            q.push(root->left);
            q.push(root->right);
        }
        
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string buff;
        
        queue<TreeNode*> q1, q2;
        while(ss >> buff)
            q1.push(buff == "#" ? NULL : new TreeNode(stoi(buff)));
        TreeNode* root = q1.front(); q1.pop();
        
        if(root) q2.push(root);
        
        while(q2.size()){
            int size = q2.size();
            for(int i = 0; i < size; i++){
                TreeNode* p = q2.front(); q2.pop();
                p->left = q1.front(); q1.pop();
                p->right = q1.front(); q1.pop();
                if (p->left) q2.push(p->left);
                if (p->right) q2.push(p->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
