// https://leetcode.com/problems/longest-univalue-path/description/

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
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;
        traverse(root, NULL, ans);
        return ans ? ans - 1 : 0;
    }
    
    int traverse(TreeNode* root, TreeNode* prev, int& ans){
        if (!root) return 0;
        
        int left = traverse(root->left, root, ans);
        int right = traverse(root->right, root, ans);
        
        ans = max(ans, 1 + left + right);
        
        return prev && prev->val == root->val ? 1 + max(left, right) : 0;
    }
};
