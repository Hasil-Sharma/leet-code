// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) swap(p, q);
        
        if (p->val <= root->val && root->val <= q->val ) return root;
        else if (p->val > root->val) return lowestCommonAncestor(root->right, p, q);
        else if (q->val < root->val) return lowestCommonAncestor(root->left, p ,q);
    }
};
