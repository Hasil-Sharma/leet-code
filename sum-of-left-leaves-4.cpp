// https://leetcode.com/problems/sum-of-left-leaves/description/

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
    int sumOfLeftLeaves(TreeNode* root, bool l = false) {
        if (!root) return 0;
        int ans = 0;
        ans += sumOfLeftLeaves(root->left, true);
        ans += sumOfLeftLeaves(root->right, false);
        if (!root->right && !root->left && l) ans = root->val;
        return ans; 
    }
};
