// https://leetcode.com/problems/path-sum/description/

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
    struct RecBlock {
        int sum;
        TreeNode* node;
        RecBlock(TreeNode* n, int s) : sum(s), node(n) {}
    };
    
    bool hasPathSum(TreeNode* root, int sum) {
        stack<RecBlock*> stk;
        stk.push(new RecBlock(root, 0));
        
        while(!stk.empty()){
            auto top = stk.top();
            stk.pop();
            if (!top->node)
                continue;
            if (!top->node->left && !top->node->right && top->sum + top->node->val == sum) 
                return true;
            else {
                stk.push(new RecBlock(top->node->left, top->sum + top->node->val));
                stk.push(new RecBlock(top->node->right, top->sum + top->node->val));
            }
        }
        
        return false;
    }
};
