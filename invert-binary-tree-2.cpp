// https://leetcode.com/problems/invert-binary-tree/description/

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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* ans = NULL;
        helper(root, &ans);
        return ans;
    }
    
    void helper(TreeNode* root, TreeNode** ans){
        if (!root){
            *ans = NULL;
        } else {
            *ans = new TreeNode(root->val);
            helper(root->left, &((*ans)->right));
            helper(root->right, &((*ans)->left));
        }
    }
};
