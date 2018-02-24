// https://leetcode.com/problems/balanced-binary-tree/description/
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
    int height(TreeNode* node){
        if (!node) return 0;
        int left = height(node->left), right = height(node->right);
        if (left != -1 && right != -1){
            // both the heights are valid
            int diff = left - right;
            if (abs(diff) < 2) return max(left, right) + 1;
            else return -1;
        } else return -1;
    }
    
    bool isBalanced(TreeNode* root) {
        return height(root) == -1 ? false : true;
    }
};
