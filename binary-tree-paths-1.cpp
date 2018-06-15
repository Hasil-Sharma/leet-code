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
    
    void helper(TreeNode* root){
        if (root->left == NULL && root->right == NULL){
            stringstream ss;
            ss << temp[0]->val;
            for(int i = 1; i < temp.size(); i++){
                ss << "->";
                ss << temp[i]->val;
            }
            ans.push_back(ss.str());
            return;
        }
        
        if (root->left){
            temp.push_back(root->left);
            helper(root->left);
            temp.pop_back();
        }
        
        if (root->right){
            temp.push_back(root->right);
            helper(root->right);
            temp.pop_back();
        }
        
    }
    vector<string> binaryTreePaths(TreeNode * root) {
        // write your code here
        if (root){
            temp.push_back(root);
            helper(root);
            temp.pop_back();
        }
        return ans;
    }
};
