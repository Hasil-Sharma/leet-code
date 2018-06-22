// https://leetcode.com/problems/merge-two-binary-trees/description/

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* t = NULL, *temp;
        stack<pair<TreeNode**, pair<TreeNode*,TreeNode*>>> stk;
        
        if (!t1 && !t2)
            return t;
        
        stk.push(make_pair(&t, make_pair(t1, t2)));
        
        while(!stk.empty()){
            auto top = stk.top();
            auto nodes = top.second;
            stk.pop();
            if (nodes.first && nodes.second){
                temp = new TreeNode(nodes.first->val + nodes.second->val);
                *top.first = temp;
                stk.push(make_pair(&temp->left, make_pair(nodes.first->left, nodes.second->left)));
                stk.push(make_pair(&temp->right, make_pair(nodes.first->right, nodes.second->right)));
            } else if (nodes.first){
                temp = new TreeNode(nodes.first->val);
                *(top.first) = temp;
                temp->left = nodes.first->left;
                temp->right = nodes.first->right;
            } else if (nodes.second){
                temp = new TreeNode(nodes.second->val);
                *(top.first) = temp;
                temp->left = nodes.second->left;
                temp->right = nodes.second->right;
            }
        }
        
        return t;
    }
};
