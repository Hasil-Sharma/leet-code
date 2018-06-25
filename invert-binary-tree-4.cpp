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
        TreeNode *ans;
        
        queue<pair<TreeNode*, TreeNode*&>> q;
        
        q.push({root, ans});
        
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            top.second = top.first;
            if (top.first){
                q.push({top.first->left, top.second->right});
                q.push({top.first->right, top.second->left});
            }
        }
        return ans;
    }
};
