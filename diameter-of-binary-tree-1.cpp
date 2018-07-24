// https://www.lintcode.com/problem/diameter-of-binary-tree/description

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: a root of binary tree
     * @return: return a integer
     */
    int diameterOfBinaryTree(TreeNode * root) {
        // write your code here
        int ans = 0;
        helper(root, ans);
        return ans;
    }
    
    int helper(TreeNode* root, int& ans){
        if(!root) return 0;
        int left = helper(root->left, ans);
        int right = helper(root->right, ans);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    }
};
