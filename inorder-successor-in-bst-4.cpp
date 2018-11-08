// https://leetcode.com/problems/inorder-successor-in-bst/description/

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* prev = NULL;
        stack<TreeNode*> stk;
        
        while(root || !stk.empty()){
            while(root){
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();
            stk.pop();
            if (prev == p) return root;
            prev = root;
            root = root->right;
        }
        
        
        return NULL;
    }
};
