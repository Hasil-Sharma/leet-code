// https://leetcode.com/problems/binary-tree-paths/description/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: the root of the binary tree
     * @return: all root-to-leaf paths
     */
    vector<TreeNode*> temp;
    vector<string> ans;
    
    void helper(TreeNode* root, string tempStr){
        if (root->left == NULL && root->right == NULL){
            ans.push_back(tempStr);
            return;
        }
        
        if (root->left){
            temp.push_back(root->left);
            helper(root->left, tempStr + "->" + to_string(root->left->val));
            temp.pop_back();
        }
        
        if (root->right){
            temp.push_back(root->right);
            helper(root->right, tempStr + "->" + to_string(root->right->val));
            temp.pop_back();
        }
        
    }
    vector<string> binaryTreePaths(TreeNode * root) {
        // write your code here
        string tempStr;
        if (root){
            tempStr = to_string(root->val);
            temp.push_back(root);
            helper(root, tempStr);
            temp.pop_back();
        }
        return ans;
    }
};
