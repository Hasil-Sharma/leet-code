// https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        
        while(!stk.empty() || root){
            while(root){
                if(root->right) stk.push(root->right);
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();
            stk.pop();
            if (!stk.empty() && root->right == stk.top()){
                TreeNode* temp = stk.top();
                stk.pop();
                stk.push(root);
                root = temp;
            } else {
                ans.push_back(root->val);
                root = NULL;
            }
        }
        return ans;
    }
};
