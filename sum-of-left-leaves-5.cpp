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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root, sum, false);
        return sum;
    }
    
    void helper(TreeNode* root, int& sum, bool left){
        if (!root) return;
        else if (left && !root->left && !root->right) sum += root->val;
        else {
            helper(root->left, sum, true);
            helper(root->right, sum, false);
        }
    }
};
