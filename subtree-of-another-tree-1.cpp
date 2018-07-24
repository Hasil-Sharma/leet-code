// https://leetcode.com/problems/subtree-of-another-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        stringstream ss, tt;
        t2str(s, ss);
        t2str(t, tt);
        return ss.str().find(tt.str()) != -1;
    }
    
    void t2str(TreeNode* root, stringstream& str){
        if (!root){
            str << "#";
            return;
        }
        
        t2str(root->left, str);
        t2str(root->right, str);
        str << root->val;
        str << "$";
    }
};
