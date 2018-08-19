// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/submissions/1

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIter {
    stack<TreeNode*> stk;
    bool rev;
    
public:
    BSTIter(TreeNode* root, bool rev){
        this->rev = rev;
        helper(root);
    }
    
    int getN(){
        TreeNode* root = stk.top();
        stk.pop();
        int ans = root->val;
        root = rev ? root->left : root->right;
        helper(root);
        return ans;
    }
    
    void helper(TreeNode* root){
        while(root){
            stk.push(root);
            root = rev ? root->right : root->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        auto fitr = BSTIter(root, false), ritr = BSTIter(root, true);
        int s = fitr.getN(), l = ritr.getN();
        while(s < l){
            if (k == s + l) return true;
            else if (k < s + l) l = ritr.getN();
            else s = fitr.getN();
        }
        return false;
    }
};
