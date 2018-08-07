// https://leetcode.com/problems/validate-binary-search-tree/description/

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
    bool isValidBST(TreeNode* root) {
        bool init = false;
        int val;
        stack<TreeNode*> stk;
        while(!stk.empty() || root){
            while(root){
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if (!init || val < root->val) val = root->val;
            else if (val >= root->val) return false;
            init = true;
            root = root->right;
        }
        return true;
    }
};
