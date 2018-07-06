// https://leetcode.com/problems/same-tree/description/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stk;
        stk.push(p);
        stk.push(q);
        
        while(!stk.empty()){
            q = stk.top();
            stk.pop();
            p = stk.top();
            stk.pop();
            if (p && q && p->val == q->val){
                stk.push(p->left);
                stk.push(q->left);
                stk.push(p->right);
                stk.push(q->right);
            } else if (!p && !q) continue;
            else return false;
        }
        
        return true;
    }
};
