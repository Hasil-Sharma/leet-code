// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
    int answer;
    int temp;
    
    int sumNumbers(TreeNode* root) {
        answer = 0;
        temp = 0;
        helper(root);        
        return answer;
    }
    
    void helper(TreeNode* root){
        if(!root) return;

        temp = temp*10 + root->val;
        
        if (root->left)
            helper(root->left);
        if (root->right)
            helper(root->right);
        else if (!root->left){
            answer += temp;
        }
        
        temp = temp / 10;
        
    }
};
