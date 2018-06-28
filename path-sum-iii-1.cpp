// https://leetcode.com/problems/path-sum-iii/description/

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
    int pathSum(TreeNode* root, int sum) {
        if (!root) return ans;
        helper(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return ans;
    }
    
    void helper(TreeNode* root, int sum){
        if (!root) return;
        if (root->val == sum) ans++;
        helper(root->left, sum - root->val);
        helper(root->right, sum - root->val);
    }
};
