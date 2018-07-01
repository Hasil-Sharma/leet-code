// https://leetcode.com/problems/add-one-row-to-tree/description/

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (!root) return root;
        else if (d == 1){
            TreeNode *newNode = new TreeNode(v);
            newNode->left = root;
            return newNode;
        }
        
        helper(root, v, d, 1);
        return root;
    }
    
    void helper(TreeNode* root, int v, int d, int h){
        if (!root) return;
        else if (h == d - 1){
            TreeNode *left = new TreeNode(v);
            TreeNode* temp = root->left;
            root->left = left;
            left->left = temp;
            
            TreeNode *right = new TreeNode(v);
            temp = root->right;
            root->right = right;
            right->right = temp;
        } else {
            helper(root->left, v, d, h + 1);
            helper(root->right, v, d, h + 1);
        }
    }
};
