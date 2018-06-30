// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        helper(root, ans, 0);
        return ans;
    }
    
    void helper(TreeNode* root, vector<int>& ans, int depth){
        if (!root) 
            return;
        if (depth == ans.size())
            ans.push_back(INT_MIN);
        ans[depth] = max(ans[depth], root->val);
        helper(root->left, ans, depth + 1);
        helper(root->right, ans, depth + 1);
    }
};
