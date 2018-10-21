// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        if(root) stk.push(root);
        
        while(!stk.empty()){
            root = stk.top();
            ans.push_back(root->val);
            stk.pop();
            
            if(root->left) stk.push(root->left);
            if(root->right) stk.push(root->right);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
