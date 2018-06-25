// https://leetcode.com/problems/invert-binary-tree/description/

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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *ans;
        
        stack<pair<TreeNode*, TreeNode*&>> stk;
        
        stk.push({root, ans});
        
        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            top.second = top.first;
            if (top.first){
                stk.push({top.first->left, top.second->right});
                stk.push({top.first->right, top.second->left});
            }
        }
        return ans;
    }
};
