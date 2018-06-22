// https://leetcode.com/problems/trim-a-binary-search-tree/description/

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (!root) 
            return NULL;
        else if (root->val >= L && root->val <= R){
            root->left = trimBST(root->left, L , R);
            root->right = trimBST(root->right, L, R);
        } else if (root->val > R){
            root->right = NULL;
            root = trimBST(root->left, L, R);
        } else {
            root->left = NULL;
            root = trimBST(root->right, L, R);
        }
        
        return root;
    }
};
