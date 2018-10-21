// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> ans;
        if(root) stk.push(root);
        
        while(!stk.empty()){
            root = stk.top();
            stk.pop();
            ans.push_back(root->val);
            if(root->right) stk.push(root->right);
            if(root->left) stk.push(root->left);
        }
        
        return ans;
    }
};
