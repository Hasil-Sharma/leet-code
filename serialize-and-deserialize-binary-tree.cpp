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
        string ans = "{";
        int nodesInQueue = 0;
        TreeNode* node;
        queue<TreeNode*> q;
        
        if (!root){
            return ans + "}";
        }
        
        q.push(root);
            nodesInQueue++;
        while(!q.empty() && nodesInQueue){
            if((node = q.front()) != NULL){
                q.pop();
                nodesInQueue--;
                ans += to_string(node->val) + " ";
                if(node->left) nodesInQueue++;
                if(node->right) nodesInQueue++;
                q.push(node->left);
                q.push(node->right);
                
            } else {
                ans += "null ";
                q.pop();
            }
        }
        
        ans[ans.length() - 1] = '}';
        return ans;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        data.erase(0, 1);
        data.erase(data.length() - 1, 1);
        if (data.length() == 0)
            return NULL;
        stringstream ss(data);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> tokens(begin, end);
        vector<TreeNode*> nodes(tokens.size(), NULL);
        for(int i = 0; i < tokens.size(); i++){
            if (tokens[i] != "null")
                nodes[i] = new TreeNode(stoi(tokens[i]));
        }
        int root = 0, child = 1;
        
        while(child < nodes.size()){
            nodes[root]->left = nodes[child];
            if (++child < nodes.size())
            nodes[root]->right = nodes[child];
            root++;
            child++;
            while(!nodes[root]) root++;
        }
        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
