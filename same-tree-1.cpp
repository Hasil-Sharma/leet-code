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
        if (!(p || q)) return true; // both are NULL
        else if ((p && !q) || (!p && q)) return false; // one is NULL and other is not
        return (p->val == q->val) ? isSameTree(p->left, q->left) && isSameTree(p->right, q->right) : false;
        
    }
};
