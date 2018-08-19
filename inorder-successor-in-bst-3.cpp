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
        while(root && p){
            if (p->val == root->val){
                if (root->right){
                    root = root->right;
                    while(root->left)
                        root = root->left;
                    return root;
                } 
                return prev;
            } else if (p->val > root->val){
                root = root->right;
            } else {
                prev = root;
                root = root->left;
            }
        }
        return NULL;
    }
};
