// https://leetcode.com/problems/recover-binary-search-tree/description/

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
    TreeNode *p1, *p2, *prev;
    void recoverTree(TreeNode* root) {
        p1 = p2 = prev = NULL;
        helper(root);
        swap(p1->val, p2->val);
    }
    
    void helper(TreeNode* root){
        if (!root) return;
        
        helper(root->left);
        
        if (prev && prev->val > root->val){
            if (!p1 && !p2)
                p1 = prev;
            p2 = root;
        }
        
        prev = root;
        
        helper(root->right);
    }
};
