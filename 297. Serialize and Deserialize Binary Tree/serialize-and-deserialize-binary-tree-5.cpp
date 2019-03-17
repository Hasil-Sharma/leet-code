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
        
        queue<TreeNode*> qq;
        
        qq.push(root);
        int non_null = 1;
        
        while(!qq.empty() && non_null != 0){
            int size = qq.size(), count = 0;
            
            while(size--){
                root = qq.front();
                qq.pop();

                ss << (root ? to_string(root->val) + "," : "#,");
                if (!root) continue;
                qq.push(root->left);
                qq.push(root->right);
                count += (root->left || root->right);
            }
            
            non_null = count;
        }
        
        return ss.str();
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string token;
        
        queue<TreeNode*> qq1, qq2;
        while(getline(ss, token, ',')){
            if (token == "#"){
                qq2.push(NULL);
            } else {
                qq2.push(new TreeNode(stoi(token)));
            }
        }
        
        TreeNode* root = qq2.front(), *temp;
        qq2.pop();
        if (root)
            qq1.push(root);
        
        while(!qq1.empty() && !qq2.empty()){
            int size = qq1.size();
            
            while(size--){
                temp = qq1.front();
                qq1.pop();
                
                auto left = qq2.front(); qq2.pop();
                auto right = qq2.front(); qq2.pop();
                
                temp->left = left; temp->right = right;
                
                if(left) qq1.push(left);
                if(right) qq1.push(right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
