// https://www.lintcode.com/problem/sum-of-left-leaves/description

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
     * @param root: t
     * @return: the sum of all left leaves
     */
    int sumOfLeftLeaves(TreeNode * root) {
        // Write your code here
    
        int ans = 0;
        helper(root, ans, false);
        return ans;
    }
    
    void helper(TreeNode* root, int& ans, bool left){
        if (!root) return;
        else if (!root->left && !root->right && left) ans += root->val;
        helper(root->left, ans, true);
        helper(root->right, ans , false);
    }
};
