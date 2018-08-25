// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/

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
    
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode *curr = root, *pre;
        
        while(curr){
            if (curr->left){
                pre = curr->left;
                while(pre->right)
                    pre = pre->right;
                pre->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
