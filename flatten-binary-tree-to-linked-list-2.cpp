// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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
    
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if (!root) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        prev = root;
        root->left = NULL;
    }
};
