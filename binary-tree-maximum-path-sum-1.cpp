// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

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
    int maxPathSum(TreeNode* root) {
        int ans = root->val;
        helper(root, ans);
        return ans;
    }
    
    int helper(TreeNode* root, int& ans){
        if (!root) return 0;
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        
        ans = max(ans, root->val + left + right);
        ans = max(ans, root->val + max(left, right));
        return max(root->val + max(left, right), root->val);
    }
};
