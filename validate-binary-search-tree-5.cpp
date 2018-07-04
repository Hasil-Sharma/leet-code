// https://leetcode.com/problems/validate-binary-search-tree/description/

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
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        bool uninit = true;

        int prev;
        stack<TreeNode*> stk;
        while(!stk.empty() || root){
            while(root){
                stk.push(root);
                root = root->left;
            }
            
            root = stk.top();
            stk.pop();
            if (uninit){
                prev = root->val;
                uninit = false;
            } else if(prev >= root->val) {
                return false;
            }
            prev = root->val;
            root = root->right;
        }
        
        return ans;
    }
};
