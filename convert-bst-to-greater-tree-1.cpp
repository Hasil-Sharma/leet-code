// https://leetcode.com/problems/convert-bst-to-greater-tree/description/

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
    int globalValue = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root)
            return root;
        
        convertBST(root->right);
        globalValue = (root->val += globalValue);
        convertBST(root->left);
        
        return root;
    }
};
