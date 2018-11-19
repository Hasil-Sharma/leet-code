// https://leetcode.com/problems/symmetric-tree/

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* n1, TreeNode* n2){
        if (!n1 && !n2) return true;
        else if (n1 && n2 && n1->val == n2->val) return helper(n1->left, n2->right) && helper(n1->right, n2->left); 
        return false;
    }
};
