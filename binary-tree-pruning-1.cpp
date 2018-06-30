// https://leetcode.com/problems/binary-tree-pruning/description/

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
    TreeNode* pruneTree(TreeNode* root) {
        if (!root) 
            return NULL;
        
        int val = helper(root);
        if (val == 0)
            return NULL;
        return root;
    }
    
    int helper(TreeNode* root){
        if (!root) return 0;
        int lval = (root->left ? helper(root->left) : 0);
        int rval = (root->right ? helper(root->right) : 0);
        
        if (lval == 0) root->left = NULL;
        if (rval == 0) root->right = NULL;
        
        if (root->val == 0 && lval == 0 && rval == 0) {
            root = NULL;
            return 0;
        }
        return root->val + lval + rval;
    }
};
