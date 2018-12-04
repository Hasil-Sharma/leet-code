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
        stack<TreeNode*> stk;
        TreeNode* prev = NULL;
        
        while(root || !stk.empty()){
            while(root){
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();
            stk.pop();
            if (prev && prev->val >= root->val) return false;
            prev = root;
            root = root->right;
        }
        
        return true;
    }
};
