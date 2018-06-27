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
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root, bool flag = false) {
        if (flag && root && !root->left && !root->right) ans += root->val;
        else if (root){
            sumOfLeftLeaves(root->right, false);
            sumOfLeftLeaves(root->left, true);
        }
        return ans;
    }
   
};
