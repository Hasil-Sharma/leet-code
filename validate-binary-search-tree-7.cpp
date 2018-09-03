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
        TreeNode *prev = NULL;
        return inorder(root, prev);
    }
    
    bool inorder(TreeNode* root, TreeNode*& prev){
        if (!root) return true;
        bool left = inorder(root->left, prev);
        if (!left || (prev && prev->val >= root->val))
            return false;
        prev = root;
        bool right = inorder(root->right, prev);
        return right;
    }
};
