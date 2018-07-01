// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        int ans;
        TreeNode* top;
        while(!stk.empty() || root){
            while(root){
                stk.push(root);
                root = root->left;
            }
            
            top = stk.top();
            stk.pop();
            if (!top) continue;
            k--;
            if (k == 0) return top->val;
            root = top->right;
        }
    }

};
