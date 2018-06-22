// https://leetcode.com/problems/trim-a-binary-search-tree/description/

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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        TreeNode** ans = &root;
        
        stack<pair<TreeNode**, TreeNode*>> stk;
        
        stk.push({ans, root});
        
        while(!stk.empty()){
            auto top = stk.top();
            auto node = top.second;
            stk.pop();
            
            if (!node) {
                *top.first = NULL;
                continue;
            }
            else if (node->val >= L && node->val <= R){
                *top.first = node;
                stk.push({&(*top.first)->left, node->left});
                stk.push({&(*top.first)->right, node->right});
            } else if (node->val > R){
                // all the nodes in right tree are greater 
                stk.push({top.first, node->left});
                node->right = NULL;
            } else if (node->val < L){
                stk.push({top.first, node->right});
                node->left = NULL;
            }
        }
        
        
        return *ans;
    }
};
