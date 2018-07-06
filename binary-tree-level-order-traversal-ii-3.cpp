// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/

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
    deque<vector<int>> ans;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        helper(root, 0);
        return {ans.begin(), ans.end()};
    }
    
    void helper(TreeNode* root, int h){
        if (!root) return;
        else if (h == ans.size())
            ans.push_front(vector<int>());
        
        helper(root->left, ++h);
        helper(root->right, h);
        
        ans[ans.size() - h].push_back(root->val);
    }
};
