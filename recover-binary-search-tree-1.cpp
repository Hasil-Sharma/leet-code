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
    
    TreeNode *prev, *first, *second;
    void recoverTree(TreeNode* root) {
        prev = first = second = NULL;
        helper(root);
        swap(first->val, second->val);
    }
    
    void helper(TreeNode* root){
        if (!root) return;
        helper(root->left);
        if (!first && prev && prev->val > root->val)
            first = prev;
        if (first && prev && prev->val > root->val)
            second = root;
        prev = root;
        helper(root->right);
    }
};
