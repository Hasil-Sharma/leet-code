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
        TreeNode* curr, *pre, *last = NULL;
        bool flag = true;
        curr = root;
        
        while(curr != NULL){
            if (curr->left == NULL){
                if (last && last->val >= curr->val) flag = false;
                last = curr;
                curr = curr->right;
            } else {
                pre = curr->left;
                while(pre->right != NULL && pre->right != curr) pre = pre->right;
                
                if(pre->right == NULL){
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    pre->right = NULL;
                    if(last && last->val >= curr->val) flag = false;
                    last = curr;
                    curr = curr->right;
                }
            }
        }
        
        return flag;
    }
};
