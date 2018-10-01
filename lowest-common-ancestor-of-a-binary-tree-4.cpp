// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/

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
        bool left = true, right = true;
        TreeNode* ans = NULL;
        find(root, p, q, ans);
        return ans;
    }

    bool find(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans){
        if (!root || ans) return false;
        bool l = find(root->left, p, q, ans);
        bool r = find(root->right, p, q, ans);

        if (l && r) ans = root;
        else if ((l || r) && (root == p || root == q)) ans = root;

        return l || r || (root == p || root == q);
    }
};
