// https://leetcode.com/problems/symmetric-tree/description/

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
        return (root && helper(root->right, root->left)) || !root;
    }
    
    bool helper(TreeNode* t1, TreeNode* t2){
        if (!t1 && !t2) return true;
        return (t1 && t2 && t1->val == t2->val && helper(t1->right, t2->left) && helper(t2->right, t1->left));
    }
};
