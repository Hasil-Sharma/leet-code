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
    int currentVal;
    bool uninitialized = true;
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool l = isValidBST(root->left);
        if (!l) return false;
        
        if (uninitialized){
            currentVal = root->val;
            uninitialized = false;
        } else {
            if (root->val > currentVal) currentVal = root->val;
            else return false;
        }
        bool r = isValidBST(root->right);
        return r;
    }
};
