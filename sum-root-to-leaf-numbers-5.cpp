// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
    int sumNumbers(TreeNode* root) {
        int ans = 0, temp = 0;
        helper(root, ans, temp);
        return ans;
    }
    
    void helper(TreeNode* root, int& ans, int temp){
        if (!root) return;
        if (!root->left && !root->right) ans += temp*10 + root->val;
        
        helper(root->left, ans, temp*10 + root->val);
        helper(root->right, ans, temp*10 + root->val);
    }
};
