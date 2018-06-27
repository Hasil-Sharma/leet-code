// https://leetcode.com/problems/sum-of-left-leaves/submissions/1

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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0, prev = 0;
        stack<TreeNode*> stk;
        while(!stk.empty() || root){
            prev = 0;
            while(root){
                stk.push(root);
                root = root->left;
                prev = root && !root->left && !root->right ? root->val : prev;
            }
            
            ans += prev;
            root = stk.top();
            stk.pop();
            root = root->right;
        }
        
        return ans;
    }
};
