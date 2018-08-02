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
        stringstream ans;
        shelper(root, ans);
        return ans.str();
    }
    
    void shelper(TreeNode* root, stringstream& ss){
        if (!root) return;
        ss << root->val << ",";
        shelper(root->left, ss);
        shelper(root->right, ss);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        deque<int> dq;
        int n = data.length(), i = 0, temp = 0;
        while(i < n){
            if (data[i] == ','){
                dq.push_back(temp);
                temp = 0;
            } else temp = temp * 10 + (data[i] - '0');
            i++;
        }
        TreeNode* root = dhelper(dq, INT_MIN, INT_MAX);
        return root;
    }
    
    TreeNode* dhelper(deque<int>& dq, int minv, int maxv){
        TreeNode* root = NULL;
        if (dq.size() && minv < dq.front() && maxv > dq.front()){
            int val = dq.front();
            root = new TreeNode(val);
            dq.pop_front();
            root->left = dhelper(dq, minv, val);
            root->right = dhelper(dq, val, maxv);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
