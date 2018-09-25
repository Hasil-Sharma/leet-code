// https://leetcode.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        TreeNode *curr, *pre;
        curr = root;
        
        while(curr){
            if (!curr->left){
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                pre = curr->left;
                while(pre->right && pre->right != curr)
                    pre = pre->right;
                if (!pre->right){
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    ans.push_back(curr->val);
                    pre->right = NULL;
                    curr = curr->right;
                }
            }
        }
        
        return ans;
    }
};
