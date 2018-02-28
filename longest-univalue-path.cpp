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
    
    int helper(TreeNode* root, int &longest){
        if(!root) return 0;
        // in case of NULL root
        int left = helper(root->left, longest);
        int right = helper(root->right, longest);
        
        int left_len = (root->left && root->left->val == root->val) ? left + 1: 0;
        int right_len = (root->right && root->right->val == root->val) ? right + 1: 0;
        
        longest = max(longest, left_len + right_len);
        return max(right_len, left_len);
    }
    int longestUnivaluePath(TreeNode* root) {
        int answer = 0;
        helper(root, answer);
        return answer;
    }
};
