// https://leetcode.com/problems/convert-bst-to-greater-tree/submissions/1

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
    
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return root;
        stack<TreeNode*> stk;
        int sum = 0;
        TreeNode* ans = root;
        while(!stk.empty() || root){
            while(root){
                stk.push(root);
                root = root->right;
            }
            
            root = stk.top();
            stk.pop();
            root->val += sum;
            sum = root->val;
            root = root->left;
        }
        
        return ans;
    }
};
