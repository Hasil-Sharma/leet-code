// https://leetcode.com/problems/binary-tree-tilt/description/

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
    int sum = 0;
    int findTilt(TreeNode* root) {
        helper(root);
        return sum;
    }
    
    int helper(TreeNode* root){
        if (!root) return 0;
        int l = helper(root->left);
        int r = helper(root->right);
        sum += abs(l - r);
        return l + r + root->val;
    }
};
