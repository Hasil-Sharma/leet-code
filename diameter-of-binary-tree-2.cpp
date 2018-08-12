// https://leetcode.com/problems/diameter-of-binary-tree/description/

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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 1;
        helper(root, ans);
        return ans - 1;
    }
    
    int helper(TreeNode* root, int& ans){
        if (!root) return 0;
        int l = helper(root->left, ans);
        int r = helper(root->right, ans);
        ans = max(ans, l + r + 1);
        return 1 + max(l, r);
    }
};
