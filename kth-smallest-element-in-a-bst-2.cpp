// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
        int ans, i = 0;
        
        while(root || !stk.empty()){
            while (root){
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();
            stk.pop();
            if (++i == k)
                return root->val;
            root = root->right;
        }
    }
};
