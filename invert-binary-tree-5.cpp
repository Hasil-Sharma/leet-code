// https://leetcode.com/problems/invert-binary-tree/description/

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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        TreeNode* ans = root, *temp;
        q.push(root);
        
        while(!q.empty()){
            
            root = q.front();
            q.pop();
            
            if (!root){
                continue;
            }
            temp = root->right;
            root->right = root->left;
            root->left = temp;
            

            q.push(root->left);
            q.push(root->right);
        }
        
        return ans;
    }
};
