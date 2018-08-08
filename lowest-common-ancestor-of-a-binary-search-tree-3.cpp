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
        if (!root || root == p || root == q) return root;
        if (p && q && p->val > q->val) swap(p, q); // q < p
        TreeNode *left = NULL, *right = NULL;
        if (p && p->val > root->val) return lowestCommonAncestor(root->right, p, q);
        if (q && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        if (p && p->val < root->val) left = lowestCommonAncestor(root->left, p, NULL);
        if (q && q->val > root->val) right = lowestCommonAncestor(root->right, NULL, q);
        if (left && right) return root;
        return left ? left : right;
    }
};
