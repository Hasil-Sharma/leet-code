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
        queue<TreeNode*> qq;
        if (root) qq.push(root);
        
        while(!qq.empty()){
            int size = qq.size();
            while(size--){
                root = qq.front();
                qq.pop();
                if (root){
                    ss << to_string(root->val) << " ";
                    qq.push(root->left);
                    qq.push(root->right);
                } else {
                    ss << "# ";
                }
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        stringstream ss(data);
        string temp;
        queue<TreeNode*> qq;
        TreeNode* ans = NULL, *root;
        
        if(ss >> temp){
            ans = new TreeNode(stoi(temp));
            qq.push(ans);
        }
        
        while(ss >> temp){
            int size = qq.size();
            while(size--){
                root = qq.front();
                qq.pop();
                
                if (temp != "#"){
                    root->left = new TreeNode(stoi(temp));
                    qq.push(root->left);
                }
                
                ss >> temp;
                
                if (temp != "#"){
                    root->right = new TreeNode(stoi(temp));
                    qq.push(root->right);
                }
                
                if (size) ss >> temp;
            }
        }
        
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
