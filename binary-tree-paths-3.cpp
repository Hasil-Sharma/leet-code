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
    vector<string> binaryTreePaths(TreeNode * root) {
        // write your code here
        vector<string> ans;
        if (!root)
            return ans;
        stack<pair<TreeNode*, string>> stk;
        stk.push({root, to_string(root->val)});
        
        while(!stk.empty()){
            auto top = stk.top();
            auto node = top.first;
            stk.pop();
            
            if (node->left == NULL && node->right == NULL){
                ans.push_back(top.second);
            }
            if (node->right)
                stk.push({node->right, top.second + "->" + to_string(node->right->val)});
            if(top.first->left)
                stk.push({node->left, top.second + "->" + to_string(node->left->val)});
                
        }
        return ans;
    }
};
